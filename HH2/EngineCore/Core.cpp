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
	
	Actor* NewActor = SpawnActor<Actor>("Player"); //�̷� �������� �����
	//�׸��� ������ 0��°�� �÷��̾�� �ϸ� 
	Actors[0]->SetPos(100, 100); //������
	Actors[0]->SetScale(200, 200); //ũ��
	Actors[0]->SetImage(LoadingImages[0]); //�̹��� �־��� 
	

	

	Actor* Actor2 = new Actor;
	Actor2->SetPos(500, 100);
	Actor2->SetScale(200, 200);
	//�̰� ī���� Ŭ�������� �����ϸ鼭 �־��ֱ�
	Actor2->SetImage(LoadingImages[1]);
	Actor2->SettingTag(Collision::Tag::Object);
	Object.push_back(Actor2); //�������ͷ� ����
	


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
		Actors[0]->Move(10, 0);
		
		Rendering();
		CollCheck();
		//���⼭ ������ ��� �ؾ�����..
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
			Actor* _OB = Object[j]; //��ƽ� i �� j �̵� �Ǽ� ��������

			if (Collision::AABB(_AC, _OB))
			{
				Collision::Tag tagA = _AC->GetTag();
				Collision::Tag tagB = _OB->GetTag();//tag������ 

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

	// �޸� DC ����
	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP memBitmap = CreateCompatibleBitmap(hdc, Width, Height);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);	

	// �޸� DC�� ������� ����� 
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	FillRect(memDC, &rc, hBrush);


	for (int i = 0; i < Actors.size(); i++)
	{
		Actors[i]->Render(memDC); //hdc�� ���� �׸��� ���� �ƴ� memDC�� �׸��� �װ��� �����ϴ� ������� ����� ���̴�. 
	}
	for (int i = 0; i < Object.size(); i++)
	{
		Object[i]->Render(memDC);
	}



	//������۸�
	//ĵ������ �ΰ� 
	//hdc�� �ΰ� ����°��̴�. 

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
	//���� ���� 
	//LeckChecker::
}




void Core::FindImage(std::string_view _ImageName)
{
	//���� �̹����� �־�Ѳ��� 
}