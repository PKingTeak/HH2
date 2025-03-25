#include "EngineWindow.h"


EngineWindow& EngineWindow::GetInstance()
{
	static EngineWindow instance;
	return instance; //�̱��� 
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
		//������۸� ��ſ� ����� 
		return 0;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); //�ϴ� �ʷϻ� RGB(0,255,0)���� ����
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
