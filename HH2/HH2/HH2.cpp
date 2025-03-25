#include <windows.h>
#include <conio.h>
#include <gdiplus.h>
#include "EngineBase/Transform.h"
#include "EngineBase/MYImage.h"

// 윈도우 프로시저 함수 선언
LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
MYImage* Himage = nullptr; //이미지 포인터 생성
ULONG_PTR  gdiplusToken; //GDI+ 토큰이 필요함 


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) //윈도우 메인함수 histance는 왜 값일까? 포인터로 주면 본체에도 영향이 가기 때문에 값으로 준다.
{

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	SetCurrentDirectory(L"D:\\HH2\\HH2\\");  // 실행 시 리소스 루트로 강제 이동

#pragma region BaseSettingWindow
	// 윈도우 클래스 설정
	const wchar_t  CLASS_NAME[] = L"MainWindow";  //char는 멀티바이트 일때 사용하고 wchar_t는 유니코드 일때 사용한다. char는 1바이트 wchar_t는 2바이트이며 한글을 표현할때 사용한다. 
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
		L"MYWindow",                  // 윈도우 제목
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
		return 0;
	}

#pragma endregion


	ShowWindow(hwnd, nCmdShow);
	// 메시지 루프
	
	MSG msg = { }; //메세지 구조체

	while (true)
	{

		while (PeekMessage(&msg, NULL, 0, 0,PM_REMOVE)) //메세지가 있을때까지 계속 돌아감 -> 아마 다른창 볼때 멈추면 이상하니까 이렇게 한듯
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			//여기가 윈도우 TICK() 임 메세지 루프 
			//대기
		}
	}



	return 0;

	//위에 코드들 다 지워도 됨




}

// 윈도우 프로시저 함수 정의
