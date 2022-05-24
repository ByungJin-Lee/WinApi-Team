
#ifndef _NETWORK_H_

#define _NETWORK_H_
#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <process.h>

#define BUFFER_SIZE 128

typedef struct SocketEventHandler {
	void (*on_client_enter)(SOCKET client);
	void (*on_client_exit)(SOCKET client);
	void (*on_read_data)(SOCKET source, char* str, int len);
	void (*on_error)(void* source, TCHAR* error_msg);
} SocketEventHandler, *LPSocketEventHandler;

void set_socket_handler(SocketEventHandler _evtHandler);

SOCKET bulid_server(short port_addr);

SOCKET bulid_client(char* ip_addr, short port_addr);

DWORD WINAPI loop_server(void* _servSock);

DWORD WINAPI loop_server_client(void* _clientSock);

DWORD WINAPI loop_client(void* _clientSock);

void broadcast_server(char* str);

void send_to_server(char* str);

void close_stop_socket();

#endif _NETWORK_H_