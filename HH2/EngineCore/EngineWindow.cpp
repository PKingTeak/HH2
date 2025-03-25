#include "EngineWindow.h"


EngineWindow& EngineWindow::GetInstance()
{
	static EngineWindow instance;
	return instance; //싱글톤 
}


void EngineWindow::Init(HINSTANCE hInstance, int nCmdShow)
{

}

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_CREATE:
	{
	break;
	}
	case WM_DESTROY:

	case WM_KEYDOWN:
	{
		InvalidateRect(hwnd, NULL, TRUE);
		//더블버퍼링 대신에 사용함 
		return 0;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); //일단 초록색 RGB(0,255,0)으로 설정
		SelectObject(hdc, hBrush);

	

		RECT rect;
	
		//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);




		DeleteObject(hBrush);
		EndPaint(hwnd, &ps);
	}

	return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
