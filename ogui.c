#include "ogui.h"


HWND hMain, hRecord;
TCHAR str[128];
bool host;
bool first;

extern HINSTANCE g_hInst;
extern OMOK omok;

void createOmokWithEvent() {	
	create_new_omok();
	omok.on_put = OnPut;
	omok.on_lose = OnLose;
	omok.on_win = OnWin;	
	omok.on_log = OnLog;
}

void OnLog(const int value) {
	wsprintf(str, TEXT("%d"), value);	
}

void OnLose() {	
	InvalidateRect(hMain, NULL, true);
	if (IDOK == MessageBox(hMain, TEXT("You Lose!"), TEXT("ALERT"), MB_OKCANCEL)) {						
		bool single = omok.single;
		create_new_omok();
		if (!single)
			m_restart();

		InvalidateRect(hMain, NULL, TRUE);
		return;
	}
}

void OnPut(const short x, const short y, Stone t) {
	if (!omok.single) {		
		char temp[128];
		sprintf(temp, "0 %d %d", x, y);		
		if (host)
			broadcast_server(temp);
		else
			send_to_server(temp);
	}
}

void OnWin() {
	InvalidateRect(hMain, NULL, true);
	if (IDOK == MessageBox(hMain, TEXT("You Win!"), TEXT("ALERT"), MB_OKCANCEL)) {				
		bool single = omok.single;
		create_new_omok();
		if (!single)
			m_restart();
		InvalidateRect(hMain, NULL, TRUE);
		return;
	}
}

void OnMouseHover(HWND hWnd, LPGUISTRUCT lpGui, const int x, const int y) {
	if (lpGui->isDisplayProp) return;

	RECT rt;

	const int UNIT = lpGui->unit;

	int dx = HAT(x, UNIT), dy = HAT(y, UNIT);

	lpGui->hoverdStone.exist = FALSE;

	if (dx == lpGui->hoverdStone.x && dy == lpGui->hoverdStone.y) return;

	RECT_STONE(&rt, lpGui->hoverdStone.x, lpGui->hoverdStone.y, UNIT);
	InvalidateRect(hWnd, &rt, TRUE);

	if (!InMultiRange(dx, dy)) return;

	if (!IsStone(omok.r_layer[dy][dx], None)) return;

	lpGui->hoverdStone.exist = TRUE;

	lpGui->hoverdStone.x = dx, lpGui->hoverdStone.y = dy;

	RECT_STONE(&rt, dx, dy, UNIT);
	InvalidateRect(hWnd, &rt, TRUE);
}

void OnLeftBtnClick(const int x, const int y, const int UNIT) {
	short dx = (short)HAT(x, UNIT), dy = (short)HAT(y, UNIT);

	if (!InMultiRange(dx, dy)) return;

	if (!IsStone(omok.r_layer[dy][dx], None)) return;

	if(omok.single)
		put_user(dx, dy);	
	else {
		if (omok.turn) {
			if (put_client(dx, dy, first ? White : Black, true)) {
				OnWin();
			}
		}
	}
	InvalidateRect(hMain, NULL, true);
}

//Board ±×¸®±â
void drawBoard(HDC hdc, LPGUISTRUCT const lpGuiStruct) {
	const int UNIT = lpGuiStruct->unit;
	HBRUSH old = SelectObject(hdc, CreateSolidBrush(BK_RGB));

	DRAW_BACKGROUND(hdc, UNIT);

	DeleteObject(SelectObject(hdc, old));

	if (lpGuiStruct->hoverdStone.exist) {
		HOVERSTONE hover = lpGuiStruct->hoverdStone;		
		old = SelectObject(hdc, CreateSolidBrush(0x00FFFFFF));		
		DRAW_HOVER(hdc, hover.x, hover.y, UNIT);
	}

	DeleteObject(SelectObject(hdc, old));

	TRAVEL(
		if (omok.r_layer[r][c] != None) {
			if (omok.r_layer[r][c] == White)
				old = SelectObject(hdc, CreateSolidBrush(0x00FFFFFF));
			else
				old = SelectObject(hdc, CreateSolidBrush(0x00000000));
			DRAW_STONE(hdc, c, r, UNIT);
			DeleteObject(SelectObject(hdc, old));
		}
	);

	if (lpGuiStruct->isDisplayAxis) {
		SetTextColor(hdc, RGB(86, 155, 74));
		SetBkMode(hdc, TRANSPARENT);
		TRAVEL(
			wsprintf(str, TEXT("%X-%X"), r, c);
			TextOut(hdc, c * UNIT + UNIT - 10, r * UNIT + UNIT - 10, str, 3);
		);
	}

	if(lpGuiStruct->isDisplayProp){
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		TRAVEL(
			if (omok.p_layer[r][c] < 1) {													
				old = SelectObject(hdc, CreateSolidBrush(0x00000000));
				DRAW_RECT(hdc, c, r, UNIT);				
			}
			else {
				old = SelectObject(hdc, CreateSolidBrush(0x00FFFFFF));
				DRAW_RECT(hdc, c, r, UNIT);
				wsprintf(str, TEXT("%d"), omok.p_layer[r][c]);
				TextOut(hdc, c * UNIT + UNIT - 10, r * UNIT + UNIT - 10, str, 1);
			}
			DeleteObject(SelectObject(hdc, old));
		);
	}
}

enum { LB = 100 };

LRESULT CALLBACK OguiProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{	
	static GUISTRUCT guiStruct;

	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &rt);
		hMain = hWnd;		
		guiStruct.unit = (800) / (O_LENGTH + 1);
		createOmokWithEvent();				
		SocketEventHandler sock_evt_handler = {
			OnClientEnter, OnClientExit, OnReadData, OnError
		};
		set_socket_handler(sock_evt_handler);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;	
	case WM_COMMAND:
		switch (LOWORD(wParam)) {		
		case ID_PLAYER:
			guiStruct.isDisplayProp = !guiStruct.isDisplayProp;
			InvalidateRect(hWnd, NULL, TRUE);
			break;		
		case ID_MULTI:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, MultiDlgProc);
			break;
		case ID_SINGLE:
			close_stop_socket();
			create_new_omok();
			InvalidateRect(hMain, NULL, true);
			break;
		case ID_PRESULT:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc);
			break;
		}
		return 0;
	case WM_SIZE:
		GetClientRect(hWnd, &rt);
		guiStruct.unit = (800) / (O_LENGTH + 1);
		InvalidateRect(hWnd, NULL, TRUE);		
		return 0;
	case WM_LBUTTONUP:
		OnLeftBtnClick(LOWORD(lParam), HIWORD(lParam), guiStruct.unit);
		return 0;
	case WM_RBUTTONUP:
		guiStruct.isDisplayAxis = !guiStruct.isDisplayAxis;
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_MOUSEMOVE:
		if (omok.running)
			OnMouseHover(hWnd, &guiStruct, LOWORD(lParam), HIWORD(lParam));
		return 0;			
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		drawBoard(hdc, &guiStruct);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_CLOSE:
		close_stop_socket();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{	
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;	

	switch (iMessage) {
	case WM_INITDIALOG:
		GetClientRect(hDlg, &rt);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {		
		case IDOK:
			EndDialog(hDlg, IDOK);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
		break;	
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);

		for (short r = 0; r < O_LENGTH; r++) {
			for (short c = 0; c < O_LENGTH; c++) {
				wsprintf(str, TEXT("%d"), omok.p_result[r][c]);
				TextOut(hdc, c * 50 + 10, r * 20 + 10, str, lstrlen(str));
			}
		}
		EndPaint(hDlg, &ps);
		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK MultiDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam){
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	TCHAR ip[128];

	switch (iMessage) {
	case WM_INITDIALOG:
		GetClientRect(hDlg, &rt);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_HOSTBTN:
			m_open_host();
			return TRUE;
		case IDC_ENTER:						
			GetDlgItemText(hDlg, IDC_IPTXT, ip, 128);
			m_connect(ip);
			return TRUE;
		case IDOK:
			EndDialog(hDlg, IDOK);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
		break;	
	}
	return FALSE;
}

void OnClientEnter(SOCKET client) {
	//If Player enter then start
	omok.running = true;
	//If host then
	omok.turn = first;
	MessageBox(hMain, TEXT("Enter Client"), TEXT("Client"), MB_OK);
}
void OnClientExit(SOCKET client) {
	//If Player exit then stop	
	create_new_omok();
	InvalidateRect(hMain, NULL, true);
}
void OnReadData(SOCKET source, char* str, int len) {
	//<Command Tag> <x> <y>
	int x , y, tag, ret;
	x = y = tag = -1;
	sscanf(str, "%d %d %d", &tag, &x, &y);		

	switch (tag) {
	case 0:
		ret = put_client(x, y, first ? Black : White, false);		
		if (ret)
			OnLose();
		InvalidateRect(hMain, NULL, true);
		break;
	case 1:
		break;
	}
}

void OnError(void* source, TCHAR* error_msg) {
	MessageBox(hMain, error_msg, TEXT("ERROR"), MB_OK);	create_new_omok();
	create_new_omok();
	InvalidateRect(hMain, NULL, true);
}

void m_init() {
	create_new_omok();
	InvalidateRect(hMain, NULL, true);
	omok.running = false;
	omok.single = false;
	omok.turn = false;
}

void m_restart() {	
	omok.single = false;
	first = !first;	
	omok.turn = first;
}

void m_open_host() {
	m_init();
	host = true;
	first = true;
	bulid_server(OMOK_PORT);
	MessageBox(hMain, TEXT("Socket Open"), TEXT("Host"), MB_OK);
	//Wait Enter Event
}

void m_connect(TCHAR* ip) {
	m_init();
	host = false;
	first = false;
	char tempIp[256];
	WideCharToMultiByte(CP_ACP, 0, ip, 128, tempIp, 256, NULL, NULL);
	MessageBox(hMain, TEXT("Try Connect"), TEXT("Client"), MB_OK);
	bulid_client(tempIp, OMOK_PORT);
	//Wait Enter Event
}