#include "Core.h"
#include <gdiplus.h>
#include "..\EngineBase\MYImage.h"
MYImage* Himage =nullptr; //이미지 포인터 생성
ULONG_PTR  gdiplusToken; //GDI+ 토큰이 필요함 


void Core::Init(HINSTANCE hInstance)
{
	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	Gdiplus::Status status = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	if (status != Gdiplus::Ok) {
		MessageBox(NULL, L"GDI+ 초기화 실패!", L"오류", MB_OK | MB_ICONERROR);
		return;
	}
	//이걸 EngineWindow로 옮겨야 될듯 
	
	
	
}

void Core::Tick()
{
	MSG msg = {};

	while (EngineWindow::IsWindowLive())
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		
		}
	}
}