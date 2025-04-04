#include <windows.h>
#include <conio.h>
#include <gdiplus.h>
#include "EngineBase/Transform.h"
#include "EngineBase/MYImage.h"
#include "EnginePlatform/EngineWindow.h"
#include "EngineCore/Core.h"
#include "EngineBase/LeckChecker.h"

// 윈도우 프로시저 함수 선언
//LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) //윈도우 메인함수 histance는 왜 값일까? 포인터로 주면 본체에도 영향이 가기 때문에 값으로 준다.
{
	LeakCheck;
	
	
	Core::GetInstance().Init(hInstance);
	Core::GetInstance().Tick();
	
	return 0;
}

// 윈도우 프로시저 함수 정의
