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
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	 //������ �̱���

	FileLoad fileloader;

	fileloader.SetPath(fileloader.FindFloder("resource"));
	std::vector<std::string> imagePath = fileloader.GetAllImage(); //GetParent() �� �����ؾ��� 

	
	for (const auto& Path : imagePath)
	{
		std::wstring wpath(Path.begin(), Path.end());
		MYImage* img = new MYImage(wpath.c_str(), 100, 100);
		LoadingImages.push_back(img);// ���� �־� 
	}
	
	//Actor���� �Ұ���
	//Test
	Actor* Actor1 = new Actor; //�̹� ��ũ ����
	Actor1->SetPos(100, 100); //������
	Actor1->SetScale(200, 200); //ũ��
	Actor1->SetImage(LoadingImages[0]); //�̹��� �־��� 
	
	
	Actors.push_back(Actor1);


	Actor* Actor2 = new Actor;
	Actor2->SetPos(150, 100);
	Actor2->SetScale(200, 200);
	Actor2->SetImage(LoadingImages[1]);
	Actors.push_back(Actor2);
	


	//�̰� EngineWindow�� �Űܾ� �ɵ� 
	
	
	
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
			std::cout << "�浹!" << std::endl;
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
	//���� �̹����� �־�Ѳ��� 
}