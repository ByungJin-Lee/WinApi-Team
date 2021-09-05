#ifndef _FORM_H_

#define _FORM_H_

#include <Windows.h>
#include "Tetris.h"

#endif _FORM_H_

//기본 창을 만듦
HWND createDefaultForm(HINSTANCE hInst, LPCTSTR title, LPSTR lpszCmdParam);

//창을 띄우고 이벤트 루프
int APIENTRY windowShowAndLoop(HWND, int);

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void CALLBACK lncRefreshProc(HWND, UINT, UINT_PTR, DWORD);

void onKeyDown(WPARAM keyCode);
