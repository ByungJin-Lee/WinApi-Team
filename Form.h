#ifndef _FORM_H_

#define _FORM_H_

#include <Windows.h>

#endif _FORM_H_

//�⺻ â�� ����
HWND createDefaultForm(HINSTANCE, LPCTSTR);

//â�� ���� �̺�Ʈ ����
int APIENTRY windowShowAndLoop(HWND, int);

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
