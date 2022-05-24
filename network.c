#include "network.h"

WSADATA wsaData;
SocketEventHandler evtHandler;
HANDLE hMutex;
SOCKET clients[5];
int clientNumber = 0;
SOCKET sockToServ;
SOCKET curSock = NULL;
BOOL running;

void set_socket_handler(SocketEventHandler _evtHandler) {
	evtHandler = _evtHandler;
}

SOCKET bulid_server(short port_addr) {
	running = FALSE;
	//WSA
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		evtHandler.on_error(NULL, TEXT("WSAStartup error!"));
		return 0;
	}
	//Mutex
	hMutex = CreateMutex(NULL, FALSE, NULL);
	if (hMutex == NULL) {
		evtHandler.on_error(NULL, TEXT("CreateMutex error"));
		return 0;
	}

	//Socket
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN servAddr;

	if (servSock == INVALID_SOCKET) {
		evtHandler.on_error(NULL, TEXT("Server Socket error"));
		return 0;
	}
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(port_addr);

	//Bind & Listen
	if (bind(servSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		evtHandler.on_error(NULL, TEXT("bind() error"));
		return 0;
	}

	if (listen(servSock, 5) == SOCKET_ERROR) {
		evtHandler.on_error(NULL, TEXT("listen() error"));
		return 0;
	}

	DWORD dwThreadID;
	running = TRUE;
	curSock = servSock;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, loop_server, (void*)servSock, 0, (unsigned*)&dwThreadID);	
	return servSock;
}

SOCKET bulid_client(char* ip_addr, short port_addr) {
	running = FALSE;
	//WSA
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		evtHandler.on_error(NULL, TEXT("WSAStartup error!"));
		return 0;
	}

	//SOCKET
	SOCKET sock;
	SOCKADDR_IN servAddr;
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		evtHandler.on_error(NULL, TEXT("Server Socket error"));
		return 0;
	}


	//ADDR
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ip_addr);
	servAddr.sin_port = htons(port_addr);

	if (connect(sock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		evtHandler.on_error(NULL, TEXT("connect() error"));		
		return 0;
	}
	DWORD dwThreadID;
	running = TRUE;
	curSock = sock;
	sockToServ = sock;
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, loop_client, (void*)sock, 0, (unsigned*)&dwThreadID);
	return sock;
}

DWORD WINAPI loop_server(void* _servSock) {
	SOCKET servSock = (SOCKET)_servSock;
	HANDLE hThread;
	DWORD dwThreadID;
	SOCKET sockClient;
	SOCKADDR_IN clientAddr;
	int clientAddrSize;

	while (running) {
		clientAddrSize = sizeof(clientAddr);
		sockClient = accept(servSock, (SOCKADDR*)&clientAddr, &clientAddrSize);
		if (sockClient == INVALID_SOCKET) {
			evtHandler.on_error(NULL, TEXT("accept() error"));
			continue;
		}

		WaitForSingleObject(hMutex, INFINITE);
		clients[clientNumber++] = sockClient;
		ReleaseMutex(hMutex);		

		hThread = (HANDLE)_beginthreadex(NULL, 0, loop_server_client, (void*)sockClient, 0, (unsigned*)&dwThreadID);
		if (hThread == 0) {
			evtHandler.on_error(NULL, TEXT("쓰레드 생성 오류"));
			break;
		}
	}

	WSACleanup();
	return 0;
}

DWORD WINAPI loop_server_client(void* _clientSock) {
	SOCKET client = (SOCKET)_clientSock;
	evtHandler.on_client_enter(client);

	int strLen = 0;
	TCHAR msg[BUFFER_SIZE];
	memset(msg, 0, BUFFER_SIZE);
	//Read Data
	while (running && (strLen = recv(client, msg, BUFFER_SIZE, 0)) > 0)
		evtHandler.on_read_data(client, msg, strLen);

	//End Connection
	WaitForSingleObject(hMutex, INFINITE);
	for (int i = 0; i < clientNumber; i++) {   // 클라이언트 연결 종료시
		if (client == clients[i]) {
			for (; i < clientNumber - 1; i++)
				clients[i] = clients[i + 1];
			break;
		}
	}
	clientNumber--;
	ReleaseMutex(hMutex);

	closesocket(client);
	evtHandler.on_client_exit(client);
	return 0;
}

DWORD WINAPI loop_client(void* _clientSock) {
	SOCKET client = (SOCKET)_clientSock;
	evtHandler.on_client_enter(client);

	int strLen = 0;
	TCHAR msg[BUFFER_SIZE];
	memset(msg, 0, BUFFER_SIZE);
	//Read Data
	while (running && (strLen = recv(client, msg, BUFFER_SIZE, 0)) > 0)
		evtHandler.on_read_data(client, msg, strLen);		

	closesocket(client);
	evtHandler.on_client_exit(client);
	WSACleanup();
	return 0;
}

void broadcast_server(char* str) {		
	int len = strlen(str);
	WaitForSingleObject(hMutex, INFINITE);
	for (int i = 0; i < clientNumber; i++)
		send(clients[i], str, len, 0);
	ReleaseMutex(hMutex);
}

void send_to_server(char* str) {	
	send(sockToServ, str, lstrlen(str), 0);
}

void close_stop_socket() {
	running = FALSE;
	if (curSock != NULL)
		closesocket(curSock);
}