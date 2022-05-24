
#ifndef _OMOK_GUI_H_

#define _CRT_SECURE_NO_WARNINGS
#define _OMOK_GUI_H_

#include "network.h"
#include "omok.h"
#include "resource.h"
#include <stdio.h>

#define SPOS(v, u) (v * u - u/2) + u
#define LPOS(v, u) (v * u + u/2) + u
#define HSPOS(v, u) (v * u - u /4) + u
#define HLPOS(v, u) (v * u + u /4) + u
#define DRAW_STONE(hdc, x, y, u) Ellipse(hdc, SPOS(x, u), SPOS(y, u), LPOS(x, u), LPOS(y, u))
#define DRAW_HOVER(hdc, x, y, u) Rectangle(hdc, HSPOS(x, u), HSPOS(y, u), HLPOS(x, u), HLPOS(y, u))
#define DRAW_RECT(hdc, x, y, u) Rectangle(hdc, SPOS(x, u), SPOS(y, u), LPOS(x, u), LPOS(y, u))
#define DRAW_BACKGROUND(hdc, u) \
	Rectangle(hdc, 0, 0, (O_LENGTH + 1) * u, (O_LENGTH + 1) * u); \
	Rectangle(hdc, u, u, O_LENGTH * u, O_LENGTH * u); \
	for(short r = 0, R = O_LENGTH - 1; r < R; r++){ \
		MoveToEx(hdc, u, u * r + u, NULL); \
		LineTo(hdc, R * u + u, u * r + u); \
	}\
	for(short r = 0, R = O_LENGTH - 1; r < R; r++){ \
		MoveToEx(hdc, u * r + u, u, NULL); \
		LineTo(hdc, u * r + u , R * u + u); \
	}
#define RECT_STONE(lpRt, x, y, u) SetRect(lpRt, SPOS(x, u), SPOS(y, u), LPOS(x, u), LPOS(y, u))
#define BK_RGB RGB(224,184,138)
#define HAT(v, u) ((v - u/2) / u)

typedef struct HOVERSTONE {
	BOOL exist;
	int x, y;
} HOVERSTONE, * LPHOVERSTONE;

typedef struct GUISTRUCT {
	HOVERSTONE hoverdStone;
	BOOL isDisplayAxis;
	BOOL isDisplayProp;
	int unit;
} GUISTRUCT, * LPGUISTRUCT;

void createOmokWithEvent();

void restartOmok();

void OnLog(const int value);

void OnLose();

void OnPut(const short, const short, Stone);

void OnWin();

void OnMouseHover(HWND hWnd, LPGUISTRUCT lpGui, const int x, const int y);

void OnLeftBtnClick(const int x, const int y, const int UNIT);

void drawBoard(HDC hdc, LPGUISTRUCT const lpGuiStruct);

LRESULT CALLBACK OguiProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK MultiDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);

void OnClientEnter(SOCKET client);
void OnClientExit(SOCKET client);
void OnReadData(SOCKET source, char* str, int len);
void OnError(void* source, TCHAR* error_msg);

void m_init();

void m_open_host();

void m_connect(TCHAR* ip);

void m_restart();

#endif _OMOK_GUI_H_