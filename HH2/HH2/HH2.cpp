#include <windows.h>
#include <conio.h>
#include <gdiplus.h>
#include "EngineBase/Transform.h"
#include "EngineBase/MYImage.h"
#include  "EnginePlatform/EngineWindow.h"
#include "EngineCore/Core.h"

// 윈도우 프로시저 함수 선언
//LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
MYImage* Himage = nullptr; //이미지 포인터 생성
ULONG_PTR  gdiplusToken; //GDI+ 토큰이 필요함 


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) //윈도우 메인함수 histance는 왜 값일까? 포인터로 주면 본체에도 영향이 가기 때문에 값으로 준다.
{

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	Core Engine;
	Engine.Init(hInstance);
	Engine.Tick();
	return 0;
}

// 윈도우 프로시저 함수 정의
