// DDS_Kick_Test01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdint.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "WaveTable.h"

/*********************************************************
lookupTable     : 16bit (use 12bit) : 0..4096

wavePhaseRegister   : 32bit
waveTunigWord       : 32bit

//ampAmount       : 8bit
//toneAmount      : 8bit
decayAmount     : 8bit
//bpmAmount       : 8bit
**********************************************************/

#define SAMPLE_CLOCK		44100.0f	// 44.1kHz
#define LFO_SAMPLE_CLOCK	441.0f		// 441Hz

#define LOOKUP_TABLE_SIZE	1024	// Lookup Table 1個のバイト長: 10bit
#define LOKKUP_TABLE_N		2		// Lookup Table の個数

uint16_t *lookupTable[LOOKUP_TABLE_SIZE];

// Basic Wave
uint32_t wavePhaseRegister;
uint32_t waveTuningWord;
double  waveValue;

// Decay
uint32_t decayPhaseRegister;
uint32_t decayTuningWord;
uint8_t  decayAmount = 32;

// frequency > SAMPLE_CLOCK / 2^32 = about 10.27uHz
double waveFrequency = 100.0f;
double lfoFrequency = 10.0f;

int period = 4410 * 2;

int _tmain(int argc, _TCHAR* argv[])
{
	uint32_t lfoCount = 0;
	double amValue;
	double decayValue;

	_setmode(_fileno(stdout), _O_BINARY);

	// lookupTable の準備
	lookupTable[0] = waveTableSine;
	lookupTable[1] = waveTableSawtoothUp;

	// DDS用の変数の初期化
	waveTuningWord = waveFrequency * pow(2.0f, 32) / SAMPLE_CLOCK;
	decayTuningWord = lfoFrequency * pow(2.0f, 32) / SAMPLE_CLOCK;
	wavePhaseRegister = 0;
	decayPhaseRegister = 0;

	for (int i = 0; i < period; i++)
	{
		// LFO系の処理 ***********************************************************
		//
		//************************************************************************
		decayPhaseRegister += decayTuningWord;
		//printf("decayPhaseRegister: %d\n", decayPhaseRegister);

		// lookupTableのバイト長に丸める
		// 32bit -> 10bit
		uint16_t decayIndex = decayPhaseRegister >> 22;
		//printf("decayIndex: %d\n", decayIndex);

		uint16_t iDecayValue = *(lookupTable[1] + decayIndex);
		//printf("iDecayValue:\t%d\n", iDecayValue);

		decayValue = ((double)iDecayValue) * decayAmount / 256.0f;
		//printf("decayValue:\t%f\n", decayValue);

		// 浮動小数点に変換
		decayValue = decayValue / 2048.0f;
		//printf("decayValue:\t%f\n", decayValue);

		// 正負にシフト
		decayValue = decayValue - 1.0f;
		//printf("decayValue:\t%f\n", decayValue);

		// 振幅変調変数に代入
		amValue = decayValue;
		//printf("amValue:\t%f\n", amValue);
		
		// Wave系の処理 ***********************************************************
		//
		//************************************************************************
		wavePhaseRegister += waveTuningWord;
		//printf("wavePhaseRegister:\t%d\n", wavePhaseRegister);
		
		// lookupTableのバイト長に丸める
		// 32bit -> 10bit
		uint16_t index = (wavePhaseRegister) >> 22;
		//printf("index: %d\n", index);

		waveValue = *(lookupTable[0] + index);
		//printf("waveValue:\t%f\n", waveValue);

		// 浮動小数点に変換(-1.0 .. 1.0)
		waveValue = (waveValue -2048) / 2048.0f;
		//printf("waveValue:\t%f\n", waveValue);
				
		// 振幅変調 --------------------------------------------------------------
		//
		waveValue = waveValue * amValue;
		printf("%f\n", waveValue);

		// 出力値の補正 ***********************************************************
		//
		// ************************************************************************
		
		// for 12bit output (0..4096)
		int16_t output_12bit = (waveValue + 1.0f) * 2048;
		//printf("%f\t%d\n", waveValue, output_12bit);

		// for 16bit output (-32768 .. 32767)
		int16_t output_16bit_raw = waveValue * 32768;
		//printf("%d\n", output_16bit_raw); 
		//fwrite(&output_16bit_raw, sizeof(output_16bit_raw), 1, stdout);
	}

	return 0;
}
