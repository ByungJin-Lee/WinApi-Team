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

typedef struct tagObject {
	bool isExist;
	short type;
	short rot;
	int posX;
	int posY;
} Object;

//게임판 생성
BLOCK** createBoard(int x, int y);

//랜덤 객체 불러오기
short getRandomObj();

//게임판 그리기
void drawBoardOnText(BLOCK**);

//객체 그리기
bool drawObjInBoardOnText(int, int);

//객체 소환
void summonObj();

//아래 충돌 판정
bool isCollisionObjToBottom(BLOCK**);

bool isCollisionObjInHere(BLOCK**, Object);

//게임판 제거
void removeBoard(BLOCK**);

//현재 상태
char* viewStatus(char*);

//게임 시작
void startTetris(BLOCK**, int);

//게임 동작 쓰레드
void workTetris(void*);

//동작 상태 결정
void setRunning(bool);

//현재 동작 상태 확인
bool isRunning();

//멈춤
void pauseTetris();

//멈춤해제
void cancelPause();

//Object 회전 Left Right
void rotateObj(BLOCK** board, bool);

//갱신 간격
void setInterval(int interv);

//Object 아래 이동
void moveObjToBottom();

//Object 회전 및 이동 0: left 1: right 2: rotate left 3: rotate right
void moveObjWithInput(BLOCK**, short type);

//Object 좌우 이동 true : 좌 right : 우
void moveObjToLR(BLOCK**, bool);

void objToBlock(BLOCK**);

void reviewAllLine(BLOCK**);

void destoryLine(BLOCK**, int);

void pullLine(BLOCK**, int);