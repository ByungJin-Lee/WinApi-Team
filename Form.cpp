#include "Form.h"

TETRIS* tetris;

HWND createDefaultForm(HINSTANCE hInst, LPCTSTR title , LPSTR lpszCmdParam)
{    

    WNDCLASS wndClass;

    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInst;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.style = CS_VREDRAW | CS_HREDRAW;
    wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wndClass.lpszClassName = title;
    wndClass.lpszMenuName = NULL;
    wndClass.lpfnWndProc = WindowProc;
    
    RegisterClass(&wndClass);

    return CreateWindow(title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, 0);    
}

int APIENTRY windowShowAndLoop(HWND hWnd, int nCmdShow)
{
    MSG message;
    ShowWindow(hWnd, nCmdShow);    

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }    
    return (int)message.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT type, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (type) { 

    case WM_KEYDOWN:
        onKeyDown((char)wParam);
        InvalidateRect(hWnd, NULL, FALSE);
        return 0;    
    case WM_CREATE:
        tetris = createTetris(8, 14);
        if (tetris != nullptr) {
            tetris->interval = 300;
            startTetris(tetris, nullptr);
        }
        SetTimer(hWnd, 1, 300, lncRefreshProc);        
        return 0;
    case WM_TIMER:
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        if (tetris != nullptr) {
            drawTetrisOnForm(tetris, hdc);
        }
        EndPaint(hWnd, &ps);
        return 0;      
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        removeTetris(tetris);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, type, wParam, lParam);
}

void CALLBACK lncRefreshProc(HWND hWnd, UINT nMsg, UINT_PTR nIDEvent, DWORD dwTime) {
    InvalidateRect(hWnd, NULL, FALSE);
}

void onKeyDown(WPARAM keyCode)
{
    switch (keyCode) {
    case VK_LEFT:
        moveObjWithInput(tetris, 0);
        break;
    case VK_RIGHT:
        moveObjWithInput(tetris, 1);
        break;
    case VK_UP:
        moveObjWithInput(tetris, 3);
        break;
    case VK_DOWN:
        moveObjToBtm(tetris);
        break;
    }
}
