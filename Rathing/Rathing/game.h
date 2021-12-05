#pragma once
#include <string.h>
#define MAX_MUSIC (30)

struct CHUNITHM
{
	char m_name[200];
	float constant;
	int score;
	char rank[5 + 1];
	float Rating;

};

void InitGame();
void UninitGame();
void UpdateGame();
void DrawGame();
void RankGame();
void rathing();