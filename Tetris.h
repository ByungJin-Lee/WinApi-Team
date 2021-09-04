#ifndef _TETRIS_H_

#define _CRT_SECURE_NO_WARNINGS

#define _TETRIS_H_

#define B_N {0,0}
#define B_Y {1,0}

#define BLOCK_COUNT 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	short type;
	short rot;
	int posX;
	int posY;
} OBJECT;

typedef struct tagTetris {
	int width;
	int height;
	int interval;
	int end;
	int score;
	bool running;
	bool pause;
	BLOCK** board;
	OBJECT* curObj;
} TETRIS;


//게임판 생성
TETRIS* createTetris(int x, int y);

//랜덤 객체 불러오기
short getRndObj();

//게임판 그리기
void drawBoardOnText(TETRIS*);

//객체 그리기
bool drawObjInBoardOnText(TETRIS*, int, int);

//객체 소환
void summonObj(TETRIS*);

//아래 충돌 판정
bool isCollisionObjToBottom(TETRIS*);

bool isCollisionObjInHere(TETRIS*, OBJECT);

//게임판 제거
void removeTetris(TETRIS*);

//현재 상태
char* viewStatus(TETRIS* tetris, char*);

//게임 시작
void startTetrisOnText(TETRIS*, int);

//게임 동작 쓰레드
void workTetrisOnText(void*);

void workTetris(void*);

//Object 회전 Left Right
void rotateObj(TETRIS* board, bool);

//Object 회전 및 이동 0: left 1: right 2: rotate left 3: rotate right
void moveObjWithInput(TETRIS*, short type);

//Object 좌우 이동 true : 좌 right : 우
void moveObjToLR(TETRIS*, bool);

void moveObjToBtm(TETRIS*);

void objToBlock(TETRIS*);

void reviewAllLine(TETRIS*);

void destoryLine(TETRIS*, int);

void pullLine(TETRIS*, int);

bool checkEnd(TETRIS*);

void startTetris(TETRIS* tetris, void (*)(void*));