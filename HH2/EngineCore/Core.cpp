#include "Core.h"

void Core::Init(HINSTANCE hInstance)
{


	static bool gdiInitialized = false;
	static ULONG_PTR gdiplusToken;

	if (!gdiInitialized)
	{
		Gdiplus::GdiplusStartupInput gdiStartupInput;
		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiStartupInput, nullptr);
		gdiInitialized = true;
	}

	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	 //윈도우 싱글톤

	FileLoad fileloader;

	fileloader.SetPath(fileloader.FindFloder("resource"));
	std::vector<std::string> imagePath = fileloader.GetAllImage(); //GetParent() 로 변경해야함 

	
	for (const auto& Path : imagePath)
	{
		std::wstring wpath(Path.begin(), Path.end());
		MYImage* img = new MYImage(wpath.c_str(), 100, 100);
		LoadingImages.push_back(img);// 이제 넣어 
	}
	
	//Actor생성 할거임
	//Test
	Actor* Actor1 = new Actor; //이미 태크 생성
	Actor1->SetPos(100, 100); //포지션
	Actor1->SetScale(200, 200); //크기
	Actor1->SetImage(LoadingImages[0]); //이미지 넣었고 
	
	
	Actors.push_back(Actor1);


	Actor* Actor2 = new Actor;
	Actor2->SetPos(150, 100);
	Actor2->SetScale(200, 200);
	Actor2->SetImage(LoadingImages[1]);
	Actors.push_back(Actor2);
	


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

		if (Collision::AABB(Actors[0], Actors[1]))
		{
			std::cout << "충돌!" << std::endl;
		}
		
		Rendering();
				
	}
}

void Core::Rendering()
{
	HWND hwnd = EngineWindow::GetInstance().GetHWND();
	HDC hdc = GetDC(hwnd);
	for (int i = 0; i < Actors.size(); i++)
	{
		Actors[i]->Render(hdc);
	}
	ReleaseDC(hwnd, hdc);
}

void Core::Release()
{
	//LeckChecker::
}




void Core::FindImage(std::string_view _ImageName)
{
	//여기 이미지들 넣어둘꺼임 
}