// DDS_Kick_Test01.cpp : Defines the entry point for the console application.
//
// ���Y���}�V���p�ɐU���ϒ��݂̂��s��
// 
// Wave:  DDS�Ő���
// Decay: ���`��ԂŐ���
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

#define MAX_DECAY_LEN		(9600u)	// 2�b : 30BPM

#define LOOKUP_TABLE_SIZE	(1024u)	// Lookup Table 1�̃o�C�g��: 10bit
#define LOKKUP_TABLE_N		(1u)		// Lookup Table �̌�

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

	int decayStop = 0;	// 1: Decay�̏o�͒�~

	_setmode(_fileno(stdout), _O_BINARY);

	// lookupTable �̏���
	lookupTable[0] = waveTableSine;

	// DDS�p�̕ϐ��̏�����
	waveTuningWord = waveFrequency * pow(2.0f, 32) / SAMPLE_CLOCK;
	wavePhaseRegister = 0;

	// Decay�̍ő�l��ݒ�
	int decayPeriod = decayAmount * MAX_DECAY_LEN / 256;
	printf("decayPeriod:\t%d\n", decayPeriod);

	for (int i = 0; i < period; i++)
	{
		if (tick % (int)(SAMPLE_CLOCK /  bps) == 0) {
			// ���������Z�̂��߂Ɋۂ߂Ă���̂Œ���

			beatCount++;
			//printf("%d\t%d\n", tick, beatCount);

			// Beat�̐擪��decayCount�����Z�b�g
			decayStop = 0;
			decayCount = 0;
		}
		tick++;
		//printf("%d\n", tick);

		// Decay�̏��� ***********************************************************
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
		// Wave�n�̏��� ***********************************************************
		//
		//************************************************************************
		wavePhaseRegister += waveTuningWord;
		//printf("wavePhaseRegister:\t%d\n", wavePhaseRegister);
		
		// lookupTable�̃o�C�g���Ɋۂ߂�
		// 32bit -> 16bit
		uint16_t index = (wavePhaseRegister) >> 16;
		//printf("index: %d\n", index);

		waveValue = *(lookupTable[0] + index);
		//printf("waveValue:\t%f\n", waveValue);

		// ���������_�ɕϊ�  (-1.0 .. 1.0)
		waveValue = waveValue / 2048.0f - 1.0f;
		//printf("waveValue:\t%f\n", waveValue
		//printf("%f\t", waveValue);
				
		// �U���ϒ� --------------------------------------------------------------
		//
		waveValue = waveValue * amValue;
		//printf("%f\n", waveValue);

		// �o�͒l�̕␳ ***********************************************************
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
