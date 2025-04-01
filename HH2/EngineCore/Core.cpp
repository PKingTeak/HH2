#include "Core.h"

void Core::Init(HINSTANCE hInstance)
{
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
	Actor* Actor1 = new Actor;
	Actor1->SetPos(100, 100);
	Actor1->SetScale(200, 200);
	
	Actors.push_back(Actor1);


	Actor* Actor2 = new Actor;
	Actor2->SetPos(500, 100);
	Actor2->SetScale(200, 200);
	Actors.push_back(Actor2);
	


	//�̰� EngineWindow�� �Űܾ� �ɵ� 
	
	
	
}

void Core::Tick()
{
	MSG msg = {};

	while (EngineWindow::IsWindowLive())
	{

		HDC hdc = EngineWindow::GetInstance().GetHDC();
		
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		
		}
		
	}
}


void Core::Release()
{
	//LeckChecker::
}




void Core::FindImage(std::string_view _ImageName)
{
	//���� �̹����� �־�Ѳ��� 
}