#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <WinSock2.h>
#include "Server.h"

int main() {
	WSADATA wsaData;
	RESULT server, client;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 0;

	int sel = 0;
	unsigned short port = 0;
	char detail[1000];

	printf("0 : Server Start, 1 : Client Start");

	scanf("%d", &sel);
	scanf("%hd", &port);
	
	switch (sel) {
	case 0:				
		server = createServer(port);
		if (server.ok) {
			displayInfoAddress(detail, server.setting);
			printf("Waiting Connect at [%s].\n", detail);
			client = acceptClient(server.socket);
		}		
		closesocket(server.socket);		
		break;
	case 1:
		scanf("%s", detail);				
		client = createSocket(createDest(detail, port));
		if (client.ok) {
			printf("Success");
		}
		closesocket(client.socket);		
	}

	WSACleanup();
	return 0;
}