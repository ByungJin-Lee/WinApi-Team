#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include "Communication.h"

int main() {
	//원속 초기화
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 0;

	RESULT server, client;	

	int sel = 0, r = 0;
	unsigned short port = 0;
	char data[500];	
	printf("TCP Test \n0 : Server Start\n1 : Client Start\n: ");

	scanf("%d", &sel);	
	
	switch (sel) {
	case 0:			
		printf("port to open : ");
		scanf("%hd", &port);
		server = createServer(port);
		if (!server.ok) {
			closesocket(server.socket);
			break;
		}
		printf("Waiting Connect at [%s].\n", getInfoFromAddr(data, server.setting));
		client = acceptClient(server.socket);			
		printf("접속 확인 - [%s]\n", getIpFromAddr(data, client.setting));			
			
		memset(data, 0, sizeof(data));
		while (1) {
			printf("< ");
			scanf("%s", data);
			if (send(client.socket, data, sizeof(data), 0) > 0) {
				if (strcmp(data, "end") == 0) break;
			}
		}

		closesocket(client.socket);
		closesocket(server.socket);		
		break;
	case 1:
		printf("Enter ip : ");
		scanf("%s", data);		
		printf("Enter port : ");
		scanf("%hd", &port);
		client = createSocket(createAddr(data, port));
		if (!client.ok) {
			closesocket(client.socket);
			break;
		}
		printf("Connection Success\n");							

		while (1) {
			if ((r = recv(client.socket, data, sizeof(data), 0)) > 0) {
				printf("> %s\n", data);
				if (strcmp(data, "end") == 0) break;
			}
		}
		
		closesocket(client.socket);		
	}
	//원속 종료
	WSACleanup();
	return 0;
}