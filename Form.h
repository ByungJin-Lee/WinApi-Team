#ifndef _FORM_H_

#define _FORM_H_

#include <Windows.h>

#endif _FORM_H_

//기본 창을 만듦
HWND createDefaultForm(HINSTANCE, LPCTSTR);

//창을 띄우고 이벤트 루프
int APIENTRY windowShowAndLoop(HWND, int);

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
