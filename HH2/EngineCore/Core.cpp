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
	//����
	//Init�� �ʹ� ����
	//�̹��� initize������ ���� ���
	EngineWindow::GetInstance().Init(hInstance);
	EngineWindow::GetInstance().WindowOpen("MyWindow", { 100,100 }, { 800,600 });	 //������ �̱���

	FileLoad fileloader;

	fileloader.SetPath(fileloader.FindFloder("resource"));
	std::vector<std::string> imagePath = fileloader.GetAllImage(); //GetParent() �� �����ؾ��� 
	//�̰� �����ؼ� �������� ���� ���翩�� ����Ŀ�� �̰� �����ϴ°� ������ 

	
	for (const auto& Path : imagePath)
	{
		std::wstring wpath(Path.begin(), Path.end());
		MYImage* img = new MYImage(wpath.c_str(), 100, 100);
		LoadingImages.push_back(img);// ���� �־� 
	}
	//
	
	Actor* NewActor = SpawnActor<Actor>("Test1"); //�̷� �������� �����
	//�׸��� ������ 0��°�� �÷��̾�� �ϸ� 
	Actors[0]->SetPos(100, 100); //������
	Actors[0]->SetScale(200, 200); //ũ��
	Actors[0]->SetImage(LoadingImages[0]); //�̹��� �־��� 
	


	Actor* Actor2 = new Actor;
	Actor2->SetPos(500, 100);
	Actor2->SetScale(200, 200);
	//�̰� ī���� Ŭ�������� �����ϸ鼭 �־��ֱ�
	Actor2->SetImage(LoadingImages[1]);
	Actors.push_back(Actor2); //�������ͷ� ����
	


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
		Actors[1]->Move(-10, 0);
		
		Rendering();
	
		Sleep(20);
	}
}

void Core::CollCheck(Actor* _other)
{

	for (int i = 0; i < Actors.size(); i++)
	{
		Actors[i]->AABB(Actors[i],_other);
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