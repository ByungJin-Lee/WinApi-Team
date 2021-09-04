#define _CRT_SECURE_NO_WARNINGS

//#include "Communication.h"

#include "Tetris.h"

//#ifndef _COMMNI_H_
//#define _COMMNI_H_
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <winsock2.h>
//
//#endif _COMMNI_H_

int main() {	
	char msg[256];
	TETRIS* tetris = createTetris(8, 15);

	printf("INFO - %s\n", viewStatus(tetris, msg));
	startTetrisOnText(tetris, 500);
	printf("\nINFO - %s\n", viewStatus(tetris, msg));
	removeTetris(tetris);
	return 0;
}
