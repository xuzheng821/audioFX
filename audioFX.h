/*
 * audioFX.h
 *
 *  Created on: Dec 6, 2017
 *      Author: Dean
 */

#ifndef LIB_AUDIOFX_H_
#define LIB_AUDIOFX_H_

#include "I2S.h"
#include "dma.h"
#include "Timer.h"
#include "mdmaArbiter.h"
#include "audioFX_config.h"
#include "utility.h"

#define AUDIO_COPY(dst,src) memcpy(dst, src, AUDIO_BUFSIZE * sizeof(int32_t))
#define ARRAY_COUNT_32(x) (sizeof(x)/sizeof(q31))
#define ARRAY_END_32(x) ((const q31 *)x + ARRAY_COUNT_32(x))

#define AUDIO_SEC_TO_SAMPLES(x) ((uint32_t)(x * AUDIO_SAMPLE_RATE))
#define AUDIO_SEC_TO_BLOCKS(x) ((uint32_t)((x * AUDIO_SAMPLE_RATE)/AUDIO_BUFSIZE))

namespace FX {

static inline void interleave(q31 *x, q31 *left, q31 *right) {
	q31 *lPtr = left; q31 *rPtr = right; q31 *dPtr = x;
	for(int __intcount=0; __intcount<AUDIO_BUFSIZE; __intcount++){
		*dPtr++ = *lPtr++; *dPtr++ = *rPtr++; }
}

static inline void deinterleave(q31 *x, q31 *left, q31 *right) {
	q31 *lPtr = left; q31 *rPtr = right; q31 *dPtr = x;
	for(int __dintcount=0; __dintcount<AUDIO_BUFSIZE; __dintcount++){
		*lPtr++ = *dPtr++; *rPtr++ = *dPtr++; }
}

static inline void split(q31 *src, q31 *l, q31 *r, q31 lmix, q31 rmix){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 lo, ro;
		__asm__ volatile("%0 = %1 * %2;" : "=r"(lo) : "r"(vi), "r"(lmix));
		__asm__ volatile("%0 = %1 * %2;" : "=r"(ro) : "r"(vi), "r"(rmix));
		*l++ = lo;
		*r++ = ro;
	}
}

static inline void splitSum(q31 *src, q31 *l, q31 *r, q31 lmix, q31 rmix){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 lo, ro;
		__asm__ volatile("%0 = %1 * %2;" : "=r"(lo) : "r"(vi), "r"(lmix));
		__asm__ volatile("%0 = %1 * %2;" : "=r"(ro) : "r"(vi), "r"(rmix));
		*l++ = *l + lo;
		*r++ = *r + ro;
	}
}

static inline void gain(q31 *dst, q31 *src, q31 g){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=r"(ret) : "r"(vi), "r"(g));
		*dst++ = ret;
	}
}

static inline void zero(q31 *dst){
	memset(dst, 0, sizeof(q31)*AUDIO_BUFSIZE);
}

static inline void mix(q31 *dst, q31 *src, q31 coeff)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=r"(ret) : "r"(vi), "r"(coeff));
		*dst++ = *dst + ret;
	}
}

static inline void sum(q31 *dst, q31 *src)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = *dst + *src++;
	}
}

class AudioFX : public I2S
{
public:
	AudioFX( void );
	bool begin( void );
	void setHook( void (*fn)(int32_t *) ){ audioHook = fn; }

	void interleave(int32_t *dest, int32_t * left, int32_t *right);
	void deinterleave(int32_t * left, int32_t *right, int32_t *src);
	void deinterleave(int32_t * left, int32_t *right, int32_t *src, void (*cb)(void));
	static void (*audioHook)(int32_t *);
	static Timer _tmr;
	static MdmaArbiter _arb;

	uint8_t *tempAlloc(void *data, uint8_t size);

	static uint8_t *tempPoolPtr;
	static uint8_t tempPool[AUDIO_TEMP_POOL_SIZE];
};


};


extern FX::AudioFX fx;

#endif /* LIB_AUDIOFX_H_ */
