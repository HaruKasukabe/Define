#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef _MSC_VER
#define DISABLE_C4996   __pragma(warning(push)) __pragma(warning(disable:4996))
#define ENABLE_C4996    __pragma(warning(pop))
#else
#define DISABLE_C4996
#define ENABLE_C4996
#endif

CHUNITHM chunithm[MAX_MUSIC];
float Average = 0;

void InitGame()
{
	
	/*Excel����f�[�^���C���|�[�g����*/
	FILE *fp;
	fopen_s(&fp,"CHUNITHM.csv","r");
	/*�t�@�C���̓ǂݍ��݂Ɏ��s������I��*/
	if (fp == NULL)
	{
		printf("�t�@�C�����ǂݍ��߂܂���ł���\n");
	}
	else
	{
		for (int i = 0; i < MAX_MUSIC; i++)
		{
			fscanf(fp, "%s,%f,%d\n", chunithm[i].m_name, &chunithm[i].constant, &chunithm[i].score);
		}
	}
	fclose(fp);
}

void UninitGame()
{

}

void UpdateGame()
{
	/*�X�R�A������o�����ߐ�p�̊֐����Ăяo��*/
	RankGame();
	rathing();


}

void DrawGame()
{
	/*���[�g����ʂɕ\������*/
	for (int i = 1; i < MAX_MUSIC + 1; i++)
	{
		printf("%d�Ȗ� �Ȗ�:%s �萔:%.1f �X�R�A:%d �����N:%s ���[�g:%.2f\n", 
			i, chunithm[i-1].m_name, chunithm[i-1].constant, chunithm[i-1].score, chunithm[i-1].rank, chunithm[i-1].Rating);
	}
	printf("���σ��[�g:%3f", Average);
}

void RankGame()
{
	DISABLE_C4996
		for (int i = 0; i < MAX_MUSIC; i++)
		{
			/*�X�R�A���烉���N������o��*/
			if (chunithm[i].score >= 975000)
			{
				if (chunithm[i].score >= 990000)
				{
					if (chunithm[i].score >= 1000000)
					{
						if (chunithm[i].score >= 1005000)
						{
							if (chunithm[i].score >= 1007500)
							{
								if (chunithm[i].score >= 1009000)
								{
									/*�����N��SSS+*/
									strcpy(chunithm[i].rank, "SSS+");
									chunithm[i].Rating = chunithm[i].constant + 2.15f;
									continue;
								}
								/*�����N��SSS*/
								strcpy(chunithm[i].rank, "SSS");
								chunithm[i].Rating = chunithm[i].constant + 2 +
									(((float)chunithm[i].score - 1007500) / 10000);
								continue;
							}
							/*�����N��SS+*/
							strcpy(chunithm[i].rank, "SS+");
							chunithm[i].Rating = chunithm[i].constant + 1.5f +
								(((float)chunithm[i].score - 1005000) / 5000);
							continue;
						}
						/*�����N��SS*/
						strcpy(chunithm[i].rank, "SS");
						chunithm[i].Rating = chunithm[i].constant + 1 +
							(((float)chunithm[i].score - 1000000) / 10000);
						continue;
					}
					/*�����N��S+*/
					strcpy(chunithm[i].rank, "S+");
					chunithm[i].Rating = chunithm[i].constant + (((float)chunithm[i].score - 975000) / 25000);
					continue;
				}
				/*�����N��S*/
				strcpy(chunithm[i].rank, "S");
				chunithm[i].Rating = chunithm[i].constant + (((float)chunithm[i].score - 975000) / 25000);
				continue;
			}

		}
	ENABLE_C4996
}

void rathing()
{
	for (int i = 0; i < MAX_MUSIC; i++)
	{
		Average += chunithm[i].Rating;
	}
	Average = Average / 30;
}