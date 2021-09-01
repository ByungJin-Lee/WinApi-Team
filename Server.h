#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

#define SINF AF_INET;

typedef struct RESULT {
	int ok;
	SOCKET socket;
	sockaddr_in setting;
} RESULT;


/* Server */

//���� ������ �����ϰ� ���ε�, socketfd ��ȯ : ���� -1
RESULT createServer(unsigned short);

//���� ������ �̿��Ͽ� ���� ��⿭ ���� �� Client ���� 1:1
RESULT acceptClient(SOCKET);

/* Client */

//������ ������ �Է¹޾� �ּ� ����ü�� ������ ��, �ּҸ� ��ȯ
sockaddr_in createDest(char*, short);

//�������� ���� ���� ���� �� ���� ��û, socketfd ��ȯ : -1 ����
RESULT createSocket(sockaddr_in);

/* MORE */

//�ּ� ���� Ȯ��
void displayInfoAddress(char*, sockaddr_in);