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


	const wchar_t* imagePath = L"D:\\HH2\\HH2\\resource\\test.png";
	Himage = new MYImage(imagePath, 0, 0);
	HDC hdc = EngineWindow::GetInstance().GetHDC();
	
	if (hdc != nullptr)
	{
		Himage->Draw(hdc);
	}
	else
	{
		MessageBox(NULL, L"HDC 또는 이미지 로딩 실패!", L"오류", MB_OK | MB_ICONERROR);
	}
	//이건 말도 안되는 구조임 
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