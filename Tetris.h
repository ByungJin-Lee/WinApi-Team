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


//������ ����
TETRIS* createTetris(int x, int y);

//���� ��ü �ҷ�����
char getRndObj();

//������ �׸���
void drawBoardOnText(TETRIS*);

//��ü �׸���
bool isObjBlockInHere(TETRIS*, int, int);

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

//Object�� �ٷ� �Ʒ������� ����
void moveObjToBtm(TETRIS*);

//Object�� ������ ����
void objToBlock(TETRIS*);

//��� ���� ������
void reviewAllLine(TETRIS*);

//�ش� ���� ������
void destoryLine(TETRIS*, int);

//�ش� �� ���� �Ʒ��� ����
void pullLine(TETRIS*, int);

//���� ������ �Ǵ���
bool checkEnd(TETRIS*);

//��Ʈ������ ������
void startTetris(TETRIS* tetris, void (*)(void*));

void drawTetrisOnForm(TETRIS* tetris, HDC hdc);

//����� �ִ��� �Ǵ�, �ִٸ� ���� ��ȯ, ������ -1
char isBlockInHere(TETRIS* tetris, int x, int y);