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
char getRndObj();

//게임판 그리기
void drawBoardOnText(TETRIS*);

//객체 그리기
bool isObjBlockInHere(TETRIS*, int, int);

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

//Object를 바로 아래쪽으로 내림
void moveObjToBtm(TETRIS*);

//Object를 블럭으로 만듦
void objToBlock(TETRIS*);

//모든 줄을 검토함
void reviewAllLine(TETRIS*);

//해당 줄을 삭제함
void destoryLine(TETRIS*, int);

//해당 줄 위를 아래로 땡김
void pullLine(TETRIS*, int);

//종료 조건을 판단함
bool checkEnd(TETRIS*);

//테트리스를 시작함
void startTetris(TETRIS* tetris, void (*)(void*));

void drawTetrisOnForm(TETRIS* tetris, HDC hdc);

//블록이 있는지 판단, 있다면 색상 반환, 없으면 -1
char isBlockInHere(TETRIS* tetris, int x, int y);