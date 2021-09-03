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
	BLOCK** board = createBoard(8, 10);

	printf("INFO - %s\n", viewStatus(msg));
	startTetris(board, 1000);
	printf("\nINFO - %s\n", viewStatus(msg));
	removeBoard(board);
	return 0;
}
