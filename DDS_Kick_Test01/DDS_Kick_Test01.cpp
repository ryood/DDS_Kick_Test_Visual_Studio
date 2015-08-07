// DDS_Kick_Test01.cpp : Defines the entry point for the console application.
//
// リズムマシン用に振幅変調のみを行う
// 
// Wave:  DDSで生成
// Decay: 線形補間で生成
//

#include "stdafx.h"

#include <stdint.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "WaveTable_16bit.h"

/*********************************************************
lookupTable       : 16bit : 0..65535

wavePhaseRegister : 32bit
waveTunigWord     : 32bit

//ampAmount       : 8bit
//toneAmount      : 8bit
decayAmount       : 8bit
bpmAmount         : 8bit
**********************************************************/

#define SAMPLE_CLOCK		(4800u)		// 48kHz

#define MAX_DECAY_LEN		(9600u)	// 2秒 : 30BPM

#define LOOKUP_TABLE_SIZE	(1024u)	// Lookup Table 1個のバイト長: 10bit
#define LOKKUP_TABLE_N		(1u)		// Lookup Table の個数

uint16_t *lookupTable[LOOKUP_TABLE_SIZE];
int tick = 0;

// BPM
uint8_t bpm = 120;

// Basic Wave
uint32_t wavePhaseRegister;
uint32_t waveTuningWord;
double  waveValue;

// Decay
uint8_t decayAmount = 127;

// frequency > SAMPLE_CLOCK / 2^32 = about 10.27uHz
double waveFrequency = 60.0f;

int period = SAMPLE_CLOCK * 2;

int _tmain(int argc, _TCHAR* argv[])
{
	double amValue = 1.0f;
	double decayValue;

	double bps = (double)bpm / 60;

	int beatCount = 0;
	int decayCount = 0;

	int decayStop = 0;	// 1: Decayの出力停止

	_setmode(_fileno(stdout), _O_BINARY);

	// lookupTable の準備
	lookupTable[0] = waveTableSine;

	// DDS用の変数の初期化
	waveTuningWord = waveFrequency * pow(2.0f, 32) / SAMPLE_CLOCK;
	wavePhaseRegister = 0;

	// Decayの最大値を設定
	int decayPeriod = decayAmount * MAX_DECAY_LEN / 256;
	printf("decayPeriod:\t%d\n", decayPeriod);

	for (int i = 0; i < period; i++)
	{
		if (tick % (int)(SAMPLE_CLOCK /  bps) == 0) {
			// ↑整数演算のために丸めているので注意

			beatCount++;
			//printf("%d\t%d\n", tick, beatCount);

			// Beatの先頭でdecayCountをリセット
			decayStop = 0;
			decayCount = 0;
		}
		tick++;
		//printf("%d\n", tick);

		// Decayの処理 ***********************************************************
		//
		//***********************************************************************
		//printf("%d\t%d\n", beatCount, decayCount);
		
		if (!decayStop) {
			decayCount++;
		}

		if (decayCount == decayPeriod) {
			decayStop = 1;
			decayCount = 0;
		}

		decayValue = ((double)decayCount / decayPeriod) * UINT16_MAX;

		printf("%f\n", decayValue);

#if 0		
		// Wave系の処理 ***********************************************************
		//
		//************************************************************************
		wavePhaseRegister += waveTuningWord;
		//printf("wavePhaseRegister:\t%d\n", wavePhaseRegister);
		
		// lookupTableのバイト長に丸める
		// 32bit -> 16bit
		uint16_t index = (wavePhaseRegister) >> 16;
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
		//printf("%d\n", output_16bit_raw); 
		//fwrite(&output_16bit_raw, sizeof(output_16bit_raw), 1, stdout);
#endif
	}

	return 0;
}
