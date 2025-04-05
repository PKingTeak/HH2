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
	//비추
	//Init이 너무 많음
	//이미지 initize같은거 만들어서 묶어서
	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	 //윈도우 싱글톤

	FileLoad fileloader;

	fileloader.SetPath(fileloader.FindFloder("resource"));
	std::vector<std::string> imagePath = fileloader.GetAllImage(); //GetParent() 로 변경해야함 
	//이거 복사해서 가져오면 폴더 복사여서 ㅈㄴ커짐 이거 수정하는게 좋을듯 

	
	for (const auto& Path : imagePath)
	{
		std::wstring wpath(Path.begin(), Path.end());
		MYImage* img = new MYImage(wpath.c_str(), 100, 100);
		LoadingImages.push_back(img);// 이제 넣어 
	}
	//
	
	Actor* NewActor = SpawnActor<Actor>("Player"); //이런 느낌으로 만들어
	//그리고 예를들어서 0번째는 플레이어다 하면 
	Actors[0]->SetPos(100, 100); //포지션
	Actors[0]->SetScale(200, 200); //크기
	Actors[0]->SetImage(LoadingImages[0]); //이미지 넣었고 
	

	

	Actor* Actor2 = new Actor;
	Actor2->SetPos(500, 100);
	Actor2->SetScale(200, 200);
	//이걸 카리나 클래스에서 생성하면서 넣어주기
	Actor2->SetImage(LoadingImages[1]);
	Actor2->SettingTag(Collision::Tag::Object);
	Object.push_back(Actor2); //스폰엑터로 변경
	


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
		Actors[0]->Move(10, 0);
		
		Rendering();
		CollCheck();
		//여기서 판정을 어떻게 해야하지..
		Sleep(20);
	}
}

void Core::CollCheck()
{
	for (int i = 0; i < Actors.size(); i++)
	{
		for (int j = 0; j < Object.size(); j++)
		{
			Actor* _AC = Actors[i];
			Actor* _OB = Object[j]; //허걱슨 i 와 j 이딴 실수 하지마셈

			if (Collision::AABB(_AC, _OB))
			{
				Collision::Tag tagA = _AC->GetTag();
				Collision::Tag tagB = _OB->GetTag();//tag가져와 

				if (tagA == Collision::Tag::Actor && tagB == Collision::Tag::Object)
				{
					_OB->SetImage(_AC->GetImage());
				}
				
			}
		}
	}
	
}

void Core::Rendering()
{
	HWND hwnd = EngineWindow::GetInstance().GetHWND();
	HDC hdc = GetDC(hwnd);
		





	RECT rc;
	GetClientRect(hwnd, &rc);
	HBRUSH hbrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	FillRect(hdc, &rc, hbrush);

	int Width = rc.right - rc.left;
	int Height = rc.bottom - rc.top;

	// 메모리 DC 생성
	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP memBitmap = CreateCompatibleBitmap(hdc, Width, Height);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);	

	// 메모리 DC를 흰색으로 지우기 
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	FillRect(memDC, &rc, hBrush);


	for (int i = 0; i < Actors.size(); i++)
	{
		Actors[i]->Render(memDC); //hdc에 직접 그리는 것이 아닌 memDC에 그리고 그것을 복사하는 방식으로 사용할 것이다. 
	}
	for (int i = 0; i < Object.size(); i++)
	{
		Object[i]->Render(memDC);
	}



	//더블버퍼링
	//캔버스가 두개 
	//hdc가 두개 생기는것이다. 

	ReleaseDC(hwnd, hdc);
}

void Core::Release()
{

	MYImage* img = nullptr;
	for (int i = 0; i < LoadingImages.size(); i++)
	{
		img = LoadingImages[i];
		delete img;
	}
	for (int i = 0; i < Actors.size(); i++)
	{
		delete Actors[i];
	}
	for (int i = 0; i < Object.size(); i++)
	{
		delete Object[i];
	}
	//전부 삭제 
	//LeckChecker::
}




void Core::FindImage(std::string_view _ImageName)
{
	//여기 이미지들 넣어둘꺼임 
}