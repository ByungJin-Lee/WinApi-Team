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

//������ ����
BLOCK** createBoard(int x, int y);

//���� ��ü �ҷ�����
short getRandomObj();

//������ �׸���
void drawBoardOnText(BLOCK**);

//��ü �׸���
bool drawObjInBoardOnText(int, int);

//��ü ��ȯ
void summonObj();

//�Ʒ� �浹 ����
bool isCollisionObjToBottom(BLOCK**);

bool isCollisionObjInHere(BLOCK**, Object);

//������ ����
void removeBoard(BLOCK**);

//���� ����
char* viewStatus(char*);

//���� ����
void startTetris(BLOCK**, int);

//���� ���� ������
void workTetris(void*);

//���� ���� ����
void setRunning(bool);

//���� ���� ���� Ȯ��
bool isRunning();

//����
void pauseTetris();

//��������
void cancelPause();

//Object ȸ�� Left Right
void rotateObj(BLOCK** board, bool);

//���� ����
void setInterval(int interv);

//Object �Ʒ� �̵�
void moveObjToBottom();

//Object ȸ�� �� �̵� 0: left 1: right 2: rotate left 3: rotate right
void moveObjWithInput(BLOCK**, short type);

//Object �¿� �̵� true : �� right : ��
void moveObjToLR(BLOCK**, bool);

void objToBlock(BLOCK**);

void reviewAllLine(BLOCK**);

void destoryLine(BLOCK**, int);

void pullLine(BLOCK**, int);