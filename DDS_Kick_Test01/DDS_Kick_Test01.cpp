// DDS_Kick_Test01.cpp : Defines the entry point for the console application.
//
// リズムマシン用に振幅変調のみを行う
// 
// サンプリング・レートはLFO系とWave系の2系統
//
// Wave:  Wave系
// Decay: LFO系
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
#define LFO_DIV				10			// LFO_CLOCK = SAMPLE_CLOCK / LFO_DIV

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
uint8_t  decayAmount = 255;

// frequency > SAMPLE_CLOCK / 2^32 = about 10.27uHz
double waveFrequency = 60.0f;
double decayFrequency = 2.0f;

int period = 44100;

int _tmain(int argc, _TCHAR* argv[])
{
	uint32_t lfoCount = 1;	// 最初に1回LFO系の処理を行う
	double amValue;
	double decayValue;

	_setmode(_fileno(stdout), _O_BINARY);

	// lookupTable の準備
	lookupTable[0] = waveTableSine;
	lookupTable[1] = waveTableSawtoothDown;

	// DDS用の変数の初期化
	waveTuningWord = waveFrequency * pow(2.0f, 32) / SAMPLE_CLOCK;
	decayTuningWord = decayFrequency * pow(2.0f, 32) / (SAMPLE_CLOCK / LFO_DIV);
	wavePhaseRegister = 0;
	decayPhaseRegister = 0;

	for (int i = 0; i < period; i++)
	{
		// LFO系の処理 ***********************************************************
		//
		//************************************************************************
		if (--lfoCount == 0) {
			lfoCount = LFO_DIV;

			decayPhaseRegister += decayTuningWord;
			//printf("decayPhaseRegister: %d\n", decayPhaseRegister);

			// lookupTableのバイト長に丸める
			// 32bit -> 10bit
			uint16_t decayIndex = decayPhaseRegister >> 22;
			//printf("decayIndex: %d\n", decayIndex);

			uint16_t iDecayValue = *(lookupTable[1] + decayIndex);
			//printf("iDecayValue:\t%d\n", iDecayValue);

			// decayAmountで重み付け
			decayValue = ((double)iDecayValue) * decayAmount / 256.0f;
			//printf("decayValue:\t%f\n", decayValue);

			// 浮動小数点に変換 (0.0 .. 1.0)
			decayValue = decayValue / 4096.0f;
			//printf("decayValue:\t%f\n", decayValue);

			// 振幅変調変数に代入
			amValue = decayValue;
			//printf("amValue:\t%f\n", amValue);
		}		
		//printf("%f\t", amValue);

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

		// 浮動小数点に変換  (-1.0 .. 1.0)
		waveValue = waveValue / 2048.0f - 1.0f;
		//printf("waveValue:\t%f\n", waveValue
		//printf("%f\t", waveValue);
				
		// 振幅変調 --------------------------------------------------------------
		//
		waveValue = waveValue * amValue;
		//printf("%f\n", waveValue);

		// 出力値の補正 ***********************************************************
		//
		// ************************************************************************
		// for 12bit output (0..4096)
		int16_t output_12bit = (waveValue + 1.0f) * 2048;
		//printf("%d\n", output_12bit);

		// for 16bit output (-32768 .. 32767)
		int16_t output_16bit_raw = waveValue * 32768;
		printf("%d\n", output_16bit_raw); 
		//fwrite(&output_16bit_raw, sizeof(output_16bit_raw), 1, stdout);
	}

	return 0;
}
