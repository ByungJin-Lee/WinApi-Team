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


//������ ����
TETRIS* createTetris(int x, int y);

//���� ��ü �ҷ�����
short getRndObj();

//������ �׸���
void drawBoardOnText(TETRIS*);

//��ü �׸���
bool drawObjInBoardOnText(TETRIS*, int, int);

//��ü ��ȯ
void summonObj(TETRIS*);

//�Ʒ� �浹 ����
bool isCollisionObjToBottom(TETRIS*);

bool isCollisionObjInHere(TETRIS*, OBJECT);

//������ ����
void removeTetris(TETRIS*);

//���� ����
char* viewStatus(TETRIS* tetris, char*);

//���� ����
void startTetrisOnText(TETRIS*, int);

//���� ���� ������
void workTetrisOnText(void*);

void workTetris(void*);

//Object ȸ�� Left Right
void rotateObj(TETRIS* board, bool);

//Object ȸ�� �� �̵� 0: left 1: right 2: rotate left 3: rotate right
void moveObjWithInput(TETRIS*, short type);

//Object �¿� �̵� true : �� right : ��
void moveObjToLR(TETRIS*, bool);

void moveObjToBtm(TETRIS*);

void objToBlock(TETRIS*);

void reviewAllLine(TETRIS*);

void destoryLine(TETRIS*, int);

void pullLine(TETRIS*, int);

bool checkEnd(TETRIS*);

void startTetris(TETRIS* tetris, void (*)(void*));