#ifndef _FORM_H_

#define _FORM_H_

#include <Windows.h>
#include "Tetris.h"

#endif _FORM_H_

//�⺻ â�� ����
HWND createDefaultForm(HINSTANCE hInst, LPCTSTR title, LPSTR lpszCmdParam);

//â�� ���� �̺�Ʈ ����
int APIENTRY windowShowAndLoop(HWND, int);

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void CALLBACK lncRefreshProc(HWND, UINT, UINT_PTR, DWORD);

void onKeyDown(WPARAM keyCode);
