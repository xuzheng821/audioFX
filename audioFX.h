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
	for(int __dintcount=AUDIO_BUFSIZE; __dintcount>0; __dintcount--){
		*x++ = *left++; *x++ = *right++; }
}

static inline void deinterleave(q31 *x, q31 *left, q31 *right) {
	for(int __dintcount=AUDIO_BUFSIZE; __dintcount>0; __dintcount--){
		*left++ = *x++; *right++ = *x++; }
}

static inline void deinterleave(q31 *x, q31 *left) {
	for(int __dintcount=AUDIO_BUFSIZE; __dintcount>0; __dintcount--){
		*left++ = *x; x += 2; }
}

static inline void split(q31 *src, q31 *l, q31 *r, q31 lmix, q31 rmix){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 lo, ro;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(lo) : "d"(vi), "d"(lmix));
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ro) : "d"(vi), "d"(rmix));
		*l++ = lo;
		*r++ = ro;
	}
}

static inline void splitSum(q31 *src, q31 *l, q31 *r, q31 lmix, q31 rmix){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 lo, ro;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(lo) : "d"(vi), "d"(lmix));
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ro) : "d"(vi), "d"(rmix));
		*l++ = *l + lo;
		*r++ = *r + ro;
	}
}

static inline void splitSum(q31 *src, q31 *l, q31 *r, q31 *lmix, q31 *rmix){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 lv = *lmix++;
		q31 rv = *rmix++;
		q31 lo, ro;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(lo) : "d"(vi), "d"(lv));
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ro) : "d"(vi), "d"(rv));
		*l++ = *l + lo;
		*r++ = *r + ro;
	}
}

static inline void gain(q31 *dst, q31 *src, q31 g){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ret) : "d"(vi), "d"(g));
		*dst++ = ret;
	}
}

static inline void gain(q31 *dst, q31 *src, q31 *g){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 c = *g++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ret) : "d"(vi), "d"(c));
		*dst++ = ret;
	}
}

static inline void gain(q15 *dst, q15 *src, q15 g){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = __builtin_bfin_mult_fr1x16(*src++, g);
	}
}

static inline void gain(q15 *dst, q15 *src, q15 *g){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = __builtin_bfin_mult_fr1x16(*src++, *g++);
	}
}

static inline void offset(q15 *dst, q15 *src, q15 o){
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = __builtin_bfin_add_fr1x16(*src++, o);
	}
}

static inline void zero(q31 *dst){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ = 0;
}

static inline void zero(q31 *dst, uint32_t size){
	for(int i=size; i>0; i--) *dst++ = 0;
}

static inline void zero(q15 *dst){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ = 0;
}

static inline void zero(q16 *dst){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ = 0;
}

static inline void fill(q15 *dst, q15 val){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ = val;
}

static inline void fill(q16 *dst, q16 val){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ = val;
}

static inline void convertAdd(q31 *dst, q15 *src){
	for(int i=0; i<AUDIO_BUFSIZE; i++) *dst++ += *src++ << 16;
}

static inline void interpolate(q16 *dst, q16 start, q16 end){
	q16 step = __builtin_bfin_abs_fr1x32(end - start)/AUDIO_BUFSIZE;
	dst[0] = start;
	if(end < start){
		q16 z = 0;
		for(int j=1; j<AUDIO_BUFSIZE; j++){
			q16 last = dst[j-1];
			q16 out;
			__asm__ volatile(
					"R7 = %1 - %2;		\n"
					"%0 = MAX(R7, %3);	\n"
			: "=d"(out) : "d"(last), "d"(step), "d"(z) : "R7");
			dst[j] = out;
		}
	}
	else if(end > start){
		for(int j=1; j<AUDIO_BUFSIZE; j++) dst[j] = start + (j * step);
	}
	else
		fill(dst, end);
}

static inline void mix(q31 *dst, q31 *src, q31 coeff)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ret) : "d"(vi), "d"(coeff));
		q31 d = *dst;
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(ret) : "d"(d), "d"(ret));
		*dst++ = ret;
	}
}

static inline void mix(q31 *dst, q31 *src, q31 *coeff)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 vi = *src++;
		q31 c = *coeff++;
		q31 ret;
		__asm__ volatile("%0 = %1 * %2;" : "=d"(ret) : "d"(vi), "d"(c));
		q31 d = *dst;
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(ret) : "d"(d), "d"(ret));
		*dst++ = ret;
	}
}

static inline void sum(q31 *dst, q31 *src, uint32_t len=AUDIO_BUFSIZE)
{
	for(int i=0; i<len; i++){
		q31 ret = *src++;
		q31 d = *dst;
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(ret) : "d"(d), "d"(ret));
		*dst++ = ret;
	}
}

static inline void sum(q15 *dst, q15 *src)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = __builtin_bfin_add_fr1x16(*src++, *dst);
	}
}



static inline void copy(q31 *dst, q31 *src)
{
	for(int i=AUDIO_BUFSIZE; i>0; i--){
		*dst++ = *src++;
	}
}

static inline void copy(q31 *dst, q31 *src, uint32_t size)
{
	for(int i=size; i>0; i--){
		*dst++ = *src++;
	}
}

static inline void copy(q15 *dst, q15 *src)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		*dst++ = *src++;
	}
}

static inline void limit24(q31 *dst)
{
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		if(*dst > 0x007FFFFF) *dst = 0x007FFFFF;
		else if(*dst < -0x007FFFFF) *dst = -0x007FFFFF;
		dst++;
	}
}

static inline void pan(q31 *src, q31 *coeffs, q31 *left, q31 *right){

	q31 mid = _F(.5);
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 c = *coeffs++;
		c = _mult32x32(c, _F(.5));
		q31 ret = *src++;
		q31 d;

		q31 v = *left;
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(d) : "d"(mid), "d"(c));
		d = _mult32x32(ret, d);
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(v) : "d"(v), "d"(d));
		*left++ = v;

		v = *right;
		__asm__ volatile("%0 = %1 - %2 (S)" : "=d"(d) : "d"(mid), "d"(c));
		d = _mult32x32(ret, d);
		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(v) : "d"(v), "d"(d));
		*right++ = v;
	}
}

static inline void wetdry(q31 *dst, q31 *src, q31 depth){

	q31 dstMul = 0x7FFFFFFF - depth;
	for(int i=0; i<AUDIO_BUFSIZE; i++){
		q31 d = _mult32x32(*dst, dstMul);
		q31 s = _mult32x32(*src++, depth);

		__asm__ volatile("%0 = %1 + %2 (S)" : "=d"(d) : "d"(s), "d"(d));
		*dst++ = d;
	}
}

static inline q31 wmin(q31 *data, uint32_t size)
{
	q31 a = 0;
	for(int i=0; i<size; i++){
		q31 d = *data++;
		a = min(a, d);
	}
	return a;
}

static inline q31 wmax(q31 *data, uint32_t size)
{
	q31 a = 0;
	for(int i=0; i<size; i++){
		q31 d = *data++;
		a = max(a, d);
	}
	return a;
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
	static MdmaArbiter _arb;
};


};


extern FX::AudioFX fx;

#endif /* LIB_AUDIOFX_H_ */
