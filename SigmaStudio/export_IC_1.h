/*
 * File:           C:\Development\swe\bsp\bf706mini\branches\1.1.0\package\BF706_EZ-Kit_MINI\Blackfin\Examples\TalkThrough_BF706Mini\SigmaStudio\export\export_IC_1.h
 *
 * Created:        Thursday, January 22, 2015 9:03:06 AM
 * Description:    TalkThrough:IC 1 program data.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright ©2015 Analog Devices, Inc. All rights reserved.
 */
#ifndef __EXPORT_IC_1_H__
#define __EXPORT_IC_1_H__

#include <SigmaStudio/export_IC_1_REG.h>

extern void SIGMA_WRITE_REGISTER_BLOCK(
		uint16_t  devAddress,
		uint16_t  regAddr,
		uint16_t  length,
		uint8_t   *pRegData);

extern void SIGMA_WRITE_DELAY(
		uint16_t  devAddress,
		uint16_t  length,
		uint8_t   *pData);

#define DEVICE_ARCHITECTURE_IC_1                  "ADAU176x"
#define DEVICE_ADDR_IC_1                          0x70

/* DSP Program Data */
#define PROGRAM_SIZE_IC_1 195
#define PROGRAM_ADDR_IC_1 2048
ADI_REG_TYPE Program_Data_IC_1[PROGRAM_SIZE_IC_1] = {
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0xE0, 0x00, 0x00, 0x00, 
0xFF, 0x34, 0x00, 0x00, 0x00, 
0xFF, 0x2C, 0x00, 0x00, 0x00, 
0xFF, 0x54, 0x00, 0x00, 0x00, 
0xFF, 0x5C, 0x00, 0x00, 0x00, 
0xFF, 0xF5, 0x08, 0x20, 0x00, 
0xFF, 0x38, 0x00, 0x00, 0x00, 
0xFF, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0xE8, 0x0C, 0x00, 0x00, 
0xFE, 0x30, 0x00, 0xE2, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFF, 0xE8, 0x07, 0x20, 0x08, 
0x00, 0x00, 0x06, 0xA0, 0x00, 
0xFF, 0xE0, 0x00, 0xC0, 0x00, 
0xFF, 0x80, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFF, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0xC0, 0x22, 0x00, 0x27, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0xE8, 0x1E, 0x00, 0x00, 
0xFF, 0xE8, 0x01, 0x20, 0x00, 
0xFF, 0xD8, 0x01, 0x03, 0x00, 
0x00, 0x07, 0xC6, 0x00, 0x00, 
0xFF, 0x08, 0x00, 0x00, 0x00, 
0xFF, 0xF4, 0x00, 0x20, 0x00, 
0xFF, 0xD8, 0x07, 0x02, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0x30, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
0xFE, 0xC0, 0x0F, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 
};

/* DSP Parameter (Coefficient) Data */
#define PARAM_SIZE_IC_1 32
#define PARAM_ADDR_IC_1 0
ADI_REG_TYPE Param_Data_IC_1[PARAM_SIZE_IC_1] = {
0x00, 0x00, 0x10, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 
};


/* Register Default - IC 1.Sample Rate Setting */
ADI_REG_TYPE R0_SAMPLE_RATE_SETTING_IC_1_Default[REG_SAMPLE_RATE_SETTING_IC_1_BYTE] = {
0x7F
};

/* Register Default - IC 1.DSP Run Register */
ADI_REG_TYPE R1_DSP_RUN_REGISTER_IC_1_Default[REG_DSP_RUN_REGISTER_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.Clock Control Register */
ADI_REG_TYPE R2_CLKCTRLREGISTER_IC_1_Default[REG_CLKCTRLREGISTER_IC_1_BYTE] = {
0x0F
};

/* Register Default - IC 1.PLL Control Register */
ADI_REG_TYPE R3_PLLCRLREGISTER_IC_1_Default[REG_PLLCRLREGISTER_IC_1_BYTE] = {
0x00, 0x01, 0x00, 0x00, 0x20, 0x01
};

/* Register Default - IC 1.Delay */
#define R4_DELAY_IC_1_ADDR 0x0
#define R4_DELAY_IC_1_SIZE 2
ADI_REG_TYPE R4_DELAY_IC_1_Default[R4_DELAY_IC_1_SIZE] = {
0x00, 0x64
};

/* Register Default - IC 1.Serial Port Control Registers */
#define R5_SERIAL_PORT_CONTROL_REGISTERS_IC_1_SIZE 2
ADI_REG_TYPE R5_SERIAL_PORT_CONTROL_REGISTERS_IC_1_Default[R5_SERIAL_PORT_CONTROL_REGISTERS_IC_1_SIZE] = {
0x01, 0x00
};

/* Register Default - IC 1.ALC Control Registers */
#define R6_ALC_CONTROL_REGISTERS_IC_1_SIZE 4
ADI_REG_TYPE R6_ALC_CONTROL_REGISTERS_IC_1_Default[R6_ALC_CONTROL_REGISTERS_IC_1_SIZE] = {
0x00, 0x00, 0x00, 0x00
};

/* Register Default - IC 1.Microphone Control Register */
ADI_REG_TYPE R7_MICCTRLREGISTER_IC_1_Default[REG_MICCTRLREGISTER_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.Record Input Signal Path Registers */
#define R8_RECORD_INPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE 8
ADI_REG_TYPE R8_RECORD_INPUT_SIGNAL_PATH_REGISTERS_IC_1_Default[R8_RECORD_INPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE] = {
0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x00, 0x00
};

/* Register Default - IC 1.ADC Control Registers */
#define R9_ADC_CONTROL_REGISTERS_IC_1_SIZE 3
ADI_REG_TYPE R9_ADC_CONTROL_REGISTERS_IC_1_Default[R9_ADC_CONTROL_REGISTERS_IC_1_SIZE] = {
0x13, 0x00, 0x00
};

/* Register Default - IC 1.Playback Output Signal Path Registers */
#define R10_PLAYBACK_OUTPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE 14
ADI_REG_TYPE R10_PLAYBACK_OUTPUT_SIGNAL_PATH_REGISTERS_IC_1_Default[R10_PLAYBACK_OUTPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE] = {
0x21, 0x00, 0x41, 0x00, 0x02, 0x08, 0x01, 0xE7, 0xE7, 0xE4, 0xE4, 0xE4, 0x00, 0x03
};

/* Register Default - IC 1.Converter Control Registers */
#define R11_CONVERTER_CONTROL_REGISTERS_IC_1_SIZE 2
ADI_REG_TYPE R11_CONVERTER_CONTROL_REGISTERS_IC_1_Default[R11_CONVERTER_CONTROL_REGISTERS_IC_1_SIZE] = {
0x00, 0x00
};

/* Register Default - IC 1.DAC Control Registers */
#define R12_DAC_CONTROL_REGISTERS_IC_1_SIZE 3
ADI_REG_TYPE R12_DAC_CONTROL_REGISTERS_IC_1_Default[R12_DAC_CONTROL_REGISTERS_IC_1_SIZE] = {
0x03, 0x00, 0x00
};

/* Register Default - IC 1.Serial Port Pad Control Registers */
#define R13_SERIAL_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE 1
ADI_REG_TYPE R13_SERIAL_PORT_PAD_CONTROL_REGISTERS_IC_1_Default[R13_SERIAL_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE] = {
0xAA
};

/* Register Default - IC 1.Communication Port Pad Control Registers */
#define R14_COMMUNICATION_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE 2
ADI_REG_TYPE R14_COMMUNICATION_PORT_PAD_CONTROL_REGISTERS_IC_1_Default[R14_COMMUNICATION_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE] = {
0xAA, 0x00
};

/* Register Default - IC 1.Jack Detect Pad Control Register */
ADI_REG_TYPE R15_JACKREGISTER_IC_1_Default[REG_JACKREGISTER_IC_1_BYTE] = {
0x08
};

/* Register Default - IC 1.DSP ON Register */
ADI_REG_TYPE R21_DSP_ENABLE_REGISTER_IC_1_Default[REG_DSP_ENABLE_REGISTER_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.CRC Registers */
#define R22_CRC_REGISTERS_IC_1_SIZE 5
ADI_REG_TYPE R22_CRC_REGISTERS_IC_1_Default[R22_CRC_REGISTERS_IC_1_SIZE] = {
0x7F, 0x7F, 0x4B, 0x7F, 0x01
};

/* Register Default - IC 1.GPIO Registers */
#define R23_GPIO_REGISTERS_IC_1_SIZE 4
ADI_REG_TYPE R23_GPIO_REGISTERS_IC_1_Default[R23_GPIO_REGISTERS_IC_1_SIZE] = {
0x00, 0x00, 0x00, 0x00
};

/* Register Default - IC 1.Non Modulo Registers */
#define R24_NON_MODULO_REGISTERS_IC_1_SIZE 2
ADI_REG_TYPE R24_NON_MODULO_REGISTERS_IC_1_Default[R24_NON_MODULO_REGISTERS_IC_1_SIZE] = {
0x10, 0x00
};

/* Register Default - IC 1.Watchdog Registers */
#define R25_WATCHDOG_REGISTERS_IC_1_SIZE 5
ADI_REG_TYPE R25_WATCHDOG_REGISTERS_IC_1_Default[R25_WATCHDOG_REGISTERS_IC_1_SIZE] = {
0x0C, 0x00, 0x00, 0x00, 0x00
};

/* Register Default - IC 1.Sampling Rate Setting Register */
ADI_REG_TYPE R26_SAMPLE_RATE_SETTING_IC_1_Default[REG_SAMPLE_RATE_SETTING_IC_1_BYTE] = {
0x7F
};

/* Register Default - IC 1.Routing Matrix Inputs Register */
ADI_REG_TYPE R27_ROUTING_MATRIX_INPUTS_IC_1_Default[REG_ROUTING_MATRIX_INPUTS_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.Routing Matrix Outputs Register */
ADI_REG_TYPE R28_ROUTING_MATRIX_OUTPUTS_IC_1_Default[REG_ROUTING_MATRIX_OUTPUTS_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.Serial Data Configuration Register */
ADI_REG_TYPE R29_SERIAL_DATAGPIO_PIN_CONFIG_IC_1_Default[REG_SERIAL_DATAGPIO_PIN_CONFIG_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.DSP Slew Mode Register */
ADI_REG_TYPE R30_DSP_SLEW_MODES_IC_1_Default[REG_DSP_SLEW_MODES_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.Serial Port Sample Rate Register */
ADI_REG_TYPE R31_SERIAL_PORT_SAMPLE_RATE_SETTING_IC_1_Default[REG_SERIAL_PORT_SAMPLE_RATE_SETTING_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.Clock Enable Registers */
#define R32_CLOCK_ENABLE_REGISTERS_IC_1_SIZE 2
ADI_REG_TYPE R32_CLOCK_ENABLE_REGISTERS_IC_1_Default[R32_CLOCK_ENABLE_REGISTERS_IC_1_SIZE] = {
0x7F, 0x03
};

/* Register Default - IC 1.Sample Rate Setting */
ADI_REG_TYPE R35_SAMPLE_RATE_SETTING_IC_1_Default[REG_SAMPLE_RATE_SETTING_IC_1_BYTE] = {
0x04
};

/* Register Default - IC 1.DSP Run Register */
ADI_REG_TYPE R36_DSP_RUN_REGISTER_IC_1_Default[REG_DSP_RUN_REGISTER_IC_1_BYTE] = {
0x01
};

/* Register Default - IC 1.Dejitter Register Control */
ADI_REG_TYPE R37_DEJITTER_REGISTER_CONTROL_IC_1_Default[REG_DEJITTER_REGISTER_CONTROL_IC_1_BYTE] = {
0x00
};

/* Register Default - IC 1.Dejitter Register Control */
ADI_REG_TYPE R38_DEJITTER_REGISTER_CONTROL_IC_1_Default[REG_DEJITTER_REGISTER_CONTROL_IC_1_BYTE] = {
0x03
};


/*
 * Default Download
 */
#define DEFAULT_DOWNLOAD_SIZE_IC_1 39

void default_download_IC_1() {
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SAMPLE_RATE_SETTING_IC_1_ADDR, REG_SAMPLE_RATE_SETTING_IC_1_BYTE, R0_SAMPLE_RATE_SETTING_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DSP_RUN_REGISTER_IC_1_ADDR, REG_DSP_RUN_REGISTER_IC_1_BYTE, R1_DSP_RUN_REGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CLKCTRLREGISTER_IC_1_ADDR, REG_CLKCTRLREGISTER_IC_1_BYTE, R2_CLKCTRLREGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLLCRLREGISTER_IC_1_ADDR, REG_PLLCRLREGISTER_IC_1_BYTE, R3_PLLCRLREGISTER_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R4_DELAY_IC_1_SIZE, R4_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_PORT_CONTROL_0_IC_1_ADDR , R5_SERIAL_PORT_CONTROL_REGISTERS_IC_1_SIZE, R5_SERIAL_PORT_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ALC_CONTROL_0_IC_1_ADDR , R6_ALC_CONTROL_REGISTERS_IC_1_SIZE, R6_ALC_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MICCTRLREGISTER_IC_1_ADDR, REG_MICCTRLREGISTER_IC_1_BYTE, R7_MICCTRLREGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_RECORD_PWR_MANAGEMENT_IC_1_ADDR , R8_RECORD_INPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE, R8_RECORD_INPUT_SIGNAL_PATH_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ADC_CONTROL_0_IC_1_ADDR , R9_ADC_CONTROL_REGISTERS_IC_1_SIZE, R9_ADC_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLAYBACK_MIXER_LEFT_CONTROL_0_IC_1_ADDR , R10_PLAYBACK_OUTPUT_SIGNAL_PATH_REGISTERS_IC_1_SIZE, R10_PLAYBACK_OUTPUT_SIGNAL_PATH_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CONVERTER_CTRL_0_IC_1_ADDR , R11_CONVERTER_CONTROL_REGISTERS_IC_1_SIZE, R11_CONVERTER_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DAC_CONTROL_0_IC_1_ADDR , R12_DAC_CONTROL_REGISTERS_IC_1_SIZE, R12_DAC_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_PORT_PAD_CONTROL_0_IC_1_ADDR , R13_SERIAL_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE, R13_SERIAL_PORT_PAD_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_COMM_PORT_PAD_CTRL_0_IC_1_ADDR , R14_COMMUNICATION_PORT_PAD_CONTROL_REGISTERS_IC_1_SIZE, R14_COMMUNICATION_PORT_PAD_CONTROL_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_JACKREGISTER_IC_1_ADDR, REG_JACKREGISTER_IC_1_BYTE, R15_JACKREGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DSP_ENABLE_REGISTER_IC_1_ADDR, REG_DSP_ENABLE_REGISTER_IC_1_BYTE, R21_DSP_ENABLE_REGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CRC_IDEAL_1_IC_1_ADDR , R22_CRC_REGISTERS_IC_1_SIZE, R22_CRC_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_GPIO_0_CONTROL_IC_1_ADDR , R23_GPIO_REGISTERS_IC_1_SIZE, R23_GPIO_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_NON_MODULO_RAM_1_IC_1_ADDR , R24_NON_MODULO_REGISTERS_IC_1_SIZE, R24_NON_MODULO_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_WATCHDOG_ENABLE_IC_1_ADDR , R25_WATCHDOG_REGISTERS_IC_1_SIZE, R25_WATCHDOG_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SAMPLE_RATE_SETTING_IC_1_ADDR, REG_SAMPLE_RATE_SETTING_IC_1_BYTE, R26_SAMPLE_RATE_SETTING_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ROUTING_MATRIX_INPUTS_IC_1_ADDR, REG_ROUTING_MATRIX_INPUTS_IC_1_BYTE, R27_ROUTING_MATRIX_INPUTS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ROUTING_MATRIX_OUTPUTS_IC_1_ADDR, REG_ROUTING_MATRIX_OUTPUTS_IC_1_BYTE, R28_ROUTING_MATRIX_OUTPUTS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_DATAGPIO_PIN_CONFIG_IC_1_ADDR, REG_SERIAL_DATAGPIO_PIN_CONFIG_IC_1_BYTE, R29_SERIAL_DATAGPIO_PIN_CONFIG_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DSP_SLEW_MODES_IC_1_ADDR, REG_DSP_SLEW_MODES_IC_1_BYTE, R30_DSP_SLEW_MODES_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_PORT_SAMPLE_RATE_SETTING_IC_1_ADDR, REG_SERIAL_PORT_SAMPLE_RATE_SETTING_IC_1_BYTE, R31_SERIAL_PORT_SAMPLE_RATE_SETTING_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_CLOCK_ENABLE_REG_0_IC_1_ADDR , R32_CLOCK_ENABLE_REGISTERS_IC_1_SIZE, R32_CLOCK_ENABLE_REGISTERS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, PARAM_ADDR_IC_1, PARAM_SIZE_IC_1, Param_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SAMPLE_RATE_SETTING_IC_1_ADDR, REG_SAMPLE_RATE_SETTING_IC_1_BYTE, R35_SAMPLE_RATE_SETTING_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DSP_RUN_REGISTER_IC_1_ADDR, REG_DSP_RUN_REGISTER_IC_1_BYTE, R36_DSP_RUN_REGISTER_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DEJITTER_REGISTER_CONTROL_IC_1_ADDR, REG_DEJITTER_REGISTER_CONTROL_IC_1_BYTE, R37_DEJITTER_REGISTER_CONTROL_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_DEJITTER_REGISTER_CONTROL_IC_1_ADDR, REG_DEJITTER_REGISTER_CONTROL_IC_1_BYTE, R38_DEJITTER_REGISTER_CONTROL_IC_1_Default );
}

#endif
