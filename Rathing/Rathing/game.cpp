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
	
	/*Excelからデータをインポートする*/
	FILE *fp;
	fopen_s(&fp,"CHUNITHM.csv","r");
	/*ファイルの読み込みに失敗したら終了*/
	if (fp == NULL)
	{
		printf("ファイルが読み込めませんでした\n");
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
	/*スコアを割り出すため専用の関数を呼び出す*/
	RankGame();
	rathing();


}

void DrawGame()
{
	/*レートを画面に表示する*/
	for (int i = 1; i < MAX_MUSIC + 1; i++)
	{
		printf("%d曲目 曲名:%s 定数:%.1f スコア:%d ランク:%s レート:%.2f\n", 
			i, chunithm[i-1].m_name, chunithm[i-1].constant, chunithm[i-1].score, chunithm[i-1].rank, chunithm[i-1].Rating);
	}
	printf("平均レート:%3f", Average);
}

void RankGame()
{
	DISABLE_C4996
		for (int i = 0; i < MAX_MUSIC; i++)
		{
			/*スコアからランクを割り出す*/
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
									/*ランクはSSS+*/
									strcpy(chunithm[i].rank, "SSS+");
									chunithm[i].Rating = chunithm[i].constant + 2.15f;
									continue;
								}
								/*ランクはSSS*/
								strcpy(chunithm[i].rank, "SSS");
								chunithm[i].Rating = chunithm[i].constant + 2 +
									(((float)chunithm[i].score - 1007500) / 10000);
								continue;
							}
							/*ランクはSS+*/
							strcpy(chunithm[i].rank, "SS+");
							chunithm[i].Rating = chunithm[i].constant + 1.5f +
								(((float)chunithm[i].score - 1005000) / 5000);
							continue;
						}
						/*ランクはSS*/
						strcpy(chunithm[i].rank, "SS");
						chunithm[i].Rating = chunithm[i].constant + 1 +
							(((float)chunithm[i].score - 1000000) / 10000);
						continue;
					}
					/*ランクはS+*/
					strcpy(chunithm[i].rank, "S+");
					chunithm[i].Rating = chunithm[i].constant + (((float)chunithm[i].score - 975000) / 25000);
					continue;
				}
				/*ランクはS*/
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