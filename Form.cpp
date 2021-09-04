#include "Form.h"

HWND createDefaultForm(HINSTANCE hInst, LPCTSTR title)
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
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        
        EndPaint(hWnd, &ps);
        return 0;        
    }
    return DefWindowProc(hWnd, type, wParam, lParam);
}
