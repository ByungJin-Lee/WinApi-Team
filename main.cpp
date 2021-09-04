#define _CRT_SECURE_NO_WARNINGS

#include "Tetris.h"

int main() {	
	char msg[256];
	TETRIS* tetris = createTetris(8, 15);

	printf("INFO - %s\n", viewStatus(tetris, msg));
	startTetrisOnText(tetris, 500);
	printf("\nINFO - %s\n", viewStatus(tetris, msg));
	removeTetris(tetris);
	return 0;
}
