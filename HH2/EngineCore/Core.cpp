#include "Core.h"
#include <gdiplus.h>
#include "..\EngineBase\MYImage.h"
MYImage* Himage =nullptr; //�̹��� ������ ����
ULONG_PTR  gdiplusToken; //GDI+ ��ū�� �ʿ��� 


void Core::Init(HINSTANCE hInstance)
{
	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	Gdiplus::Status status = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
	if (status != Gdiplus::Ok) {
		MessageBox(NULL, L"GDI+ �ʱ�ȭ ����!", L"����", MB_OK | MB_ICONERROR);
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
		MessageBox(NULL, L"HDC �Ǵ� �̹��� �ε� ����!", L"����", MB_OK | MB_ICONERROR);
	}
	//�̰� ���� �ȵǴ� ������ 
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