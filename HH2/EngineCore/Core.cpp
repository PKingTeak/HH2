#include "Core.h"
#include <gdiplus.h>
#include "..\EngineBase\MYImage.h"
#include "..\EngineBase\FileLoad.h"
#include <iostream>

void Core::Init(HINSTANCE hInstance)
{
	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	 //윈도우 싱글톤

	std::string A = std::filesystem::current_path().string();
	FileLoad fileloader;
	std::vector<std::string> imagePath = fileloader.GetAllImage("..\..\..\..\resource"); //GetParent() 로 변경해야함 

	
	for (const auto& Path : imagePath)
	{
		std::wstring wpath(Path.begin(), Path.end());
		MYImage* img = new MYImage(wpath.c_str(), 100, 100);

		LoadingImages.push_back(img);// 이제 넣어 
	}
	
	//Actor생성 할거임


	//이걸 EngineWindow로 옮겨야 될듯 
	
	
	
}

void Core::Tick()
{
	MSG msg = {};

	while (EngineWindow::IsWindowLive())
	{
		HDC hdc = EngineWindow::GetInstance().GetHDC();
		for (auto* img : LoadingImages)
		{
			img->Draw(hdc);
		}
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		
		}
	}
}


void Core::Render(HDC hdc)
{
	for (const auto& Image : LoadingImages)
	{
		Image->Draw(hdc);
	}
}