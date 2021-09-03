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

//서버 소켓을 생성하고 바인드, socketfd 반환 : 실패 -1
RESULT createServer(unsigned short);

//서버 소켓을 이용하여 연결 대기열 형성 및 Client 수립 1:1
RESULT acceptClient(SOCKET);

/* Client */

//목적지 정보를 입력받아 주소 구조체를 생성한 후, 주소를 반환
sockaddr_in createAddr(char*, unsigned short);

//목적지에 관한 소켓 생성 및 연결 요청, socketfd 반환 : -1 실패
RESULT createSocket(sockaddr_in);

/* MORE */

//주소 정보 확인
char* getInfoFromAddr(char*, sockaddr_in);

//IP 정보 확인
char* getIpFromAddr(char*, sockaddr_in);

//소켓으로 들어오는 정보 처리 함수 등록
void registerGetterThread(SOCKET, void (*)(void*));

//WSA 원속 초기화
int initEnviroment();

//WSA 원속 종료
void exitEnviroment();

#endif _COMMNI_H_