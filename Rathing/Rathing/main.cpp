#include <stdio.h>
#include "game.h"

int main(void)
{
	InitGame();
	UpdateGame();
	DrawGame();
	UninitGame();

	rewind(stdin);
	getchar();
	return 0;
}