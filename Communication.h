#ifndef _COMMNI_H_

#define _COMMNI_H_

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <winsock2.h>
#include <process.h>
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
sockaddr_in createAddr(char*, unsigned short);

//�������� ���� ���� ���� �� ���� ��û, socketfd ��ȯ : -1 ����
RESULT createSocket(sockaddr_in);

/* MORE */

//�ּ� ���� Ȯ��
char* getInfoFromAddr(char*, sockaddr_in);

//IP ���� Ȯ��
char* getIpFromAddr(char*, sockaddr_in);

//�������� ������ ���� ó�� �Լ� ���
void registerGetterThread(SOCKET, void (*)(void*));

//WSA ���� �ʱ�ȭ
int initEnviroment();

//WSA ���� ����
void exitEnviroment();

#endif _COMMNI_H_