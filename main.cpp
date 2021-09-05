#define _CRT_SECURE_NO_WARNINGS

#include "Form.h"

LPCTSTR titl = TEXT("TETRIS");

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE prevInst, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd = createDefaultForm(hInst, titl, lpszCmdParam);
	return windowShowAndLoop(hWnd, nCmdShow);
}
