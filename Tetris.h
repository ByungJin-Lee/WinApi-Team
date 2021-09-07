#ifndef _TETRIS_H_

#define _CRT_SECURE_NO_WARNINGS

#define _TETRIS_H_

#define B_N {0,0}
#define B_Y {1,0}

#define BLOCK_COUNT 7

#define RED 0
#define ORANGE 1
#define YELLOW 2
#define GREEN 3
#define PURPLE 4
#define BLUE 5
#define SKYBLUE 6
#define EMPTY -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <Windows.h>
#include <process.h>
#include <stdbool.h>

#endif _TETRIS_H_

typedef struct tagBLOCK{
	bool isBlock;
	char color;
} BLOCK;

typedef struct tagOBJECT {
	bool isExist;
	char type;		
	short rot;
	int posX;
	int posY;
} OBJECT;

typedef struct tagTetris {
	int blockSize;
	int width;
	int height;
	int initX;
	int initY;
	int interval;
	int end;
	int score;
	bool running;
	bool pause;
	BLOCK** board;
	OBJECT* curObj;
} TETRIS;


//Create Tetris and reset member
TETRIS* createTetris(int x, int y);

//Free Tetris, Clear Memory
void removeTetris(TETRIS*);

//Start Tetris
void startTetris(TETRIS* tetris, void (*)(void*));

//Thread - start running when tetris start
void workTetris(void*);

//Check all line whether is full
void checkLineIsFull(TETRIS*);

//Destory Line
void destoryLine(TETRIS*, int);

//Pull line to down when destory line
void pullLine(TETRIS*, int);

//Check Death Condition
bool checkEnd(TETRIS*);

/* About Control Object */

//Object rotate Left/Right
void rotateObj(TETRIS* board, bool);

//Object Control with Input Cmd - L(0) R(1) RL(2) RR(3)
void moveObjWithInput(TETRIS*, short type);

//Object Move L(T) R(F)
void moveObjToLR(TETRIS*, bool);

//Object move to Bottom
void moveObjToBtm(TETRIS*);

/* About Block Collision */

bool isCollisionObjToBottom(TETRIS*);

bool isCollisionObjInHere(TETRIS*, OBJECT);

bool isObjBlockInHere(TETRIS*, int, int);

//is there Block? then return block color(not -1)
char isBlockInHere(TETRIS* tetris, int x, int y);

/* simulate Block */



/* About Object */

void objToBlock(TETRIS*);

void summonObj(TETRIS*);

char getRndObj(char);

/* Tetris Control */

void pause(TETRIS*);

void flow(TETRIS*);

void restart(TETRIS*);

/* Tetris Information */

char* viewStatus(TETRIS* tetris, char*);

/* About Platform */

//On Form
void drawTetrisOnForm(TETRIS* tetris, HDC hdc);

//On Text
void startTetrisOnText(TETRIS*, int);

void drawBoardOnText(TETRIS*);

void workTetrisOnText(void*);