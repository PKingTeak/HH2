#include "EngineWindow.h"

#include <gdiplus.h>

bool EngineWindow::WindowLive = true;
HINSTANCE EngineWindow::hInstance;

EngineWindow& EngineWindow::GetInstance()
{
	static EngineWindow instance;
	return instance; //싱글톤 
}


void EngineWindow::Init(HINSTANCE _hInstance)
{
	hInstance = _hInstance;
	
}

LRESULT CALLBACK EngineWindow::MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static MYImage* WImage = nullptr;
	static ULONG_PTR gdiplusToken;
	static bool gdiInitialized = false;


	switch (uMsg)
	{
	case  WM_CREATE:
	{
		if (!gdiInitialized)
		{
			Gdiplus::GdiplusStartupInput gdiStartupInput;
			Gdiplus::GdiplusStartup(&gdiplusToken, &gdiStartupInput, nullptr);
			gdiInitialized = true;
		}
	}
		break;


	case WM_PAINT:
	{

		PAINTSTRUCT ps;     
		HDC hdc = BeginPaint(hwnd, &ps); 
		EngineWindow::GetInstance().SetHDC(hdc);
		EndPaint(hwnd, &ps);
		return 0;
	}

	break;
	case WM_DESTROY:
	{
		WindowLive = false;
		if (gdiInitialized)
		{
			Gdiplus::GdiplusShutdown(gdiplusToken);
			gdiInitialized = false;
		}
		//delete WImage;
		WImage = nullptr;
		PostQuitMessage(0);
	break;
	}
	default:
		return DefWindowProcW(hwnd, uMsg, wParam, lParam);

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


HDC EngineWindow::GetHDC() const
{
	return wHdc;
}

void EngineWindow::WindowOpen(std::string_view _WindowName, std::pair<int, int> _StartPos, std::pair<int, int> _Scale)
{
#pragma region BaseSettingWindow
	// 윈도우 클래스 설정
	const wchar_t  CLASS_NAME[] = L"MyWindow";  //char는 멀티바이트 일때 사용하고 wchar_t는 유니코드 일때 사용한다. char는 1바이트 wchar_t는 2바이트이며 한글을 표현할때 사용한다. 
	WNDCLASS wc = { };
	wc.lpfnWndProc = MainWindowProc; // RectWIndowPROC를 윈도우 프로시저로 설정
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc);
	// 윈도우 생성
	//일단 CreateWindowEx()를 돌기전에 MainWindowProc()로 가는데 이유는 우리는 wc.hIcon ~ lpszMenuName 까지 설정을 안했기 때문에 기본설정을 윈도우가 해주기 때문에
	// MainWindowProc() 에서 DefWindowProc가 먼저 호출된다. 
	HWND hwnd = CreateWindowEx(
		0,                              // 확장 윈도우 스타일
		CLASS_NAME,                     // 윈도우 클래스 이름
		L"MyWindow",                  // 윈도우 제목
		WS_OVERLAPPEDWINDOW,            // 윈도우 스타일
		// 윈도우 크기와 위치
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // 부모 윈도우 -> 느낌이 여러개의 윈도우를 띄울때 사용하는듯
		NULL,       // 메뉴
		hInstance,  // 인스턴스 핸들
		NULL        // 추가 애플리케이션 데이터
	);

	if (hwnd == NULL)
	{
		return;
	}

#pragma endregion


	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	// 메시지 루프



}