#pragma once
#include "..\EnginePlatform\EngineWindow.h"
#include "..\EngineBase\MYImage.h"

class Core
{
	
public:
	static Core& GetInstanc()
	{
		static Core instance;
		return instance;
	}

	~Core()
	{
		//���� ��������ұ�
		//
	}


	Core(const Core& _Other) = delete;
	Core(Core&& _Other) noexcept = delete;
	Core& operator=(const Core& _Other) = delete;
	Core& operator=(Core&& _Other) noexcept = delete;
	
	
	
	

	void Init(HINSTANCE hInstance);
	void Tick();
	void Render(HDC hdc);
	void FindImage(std::string_view _ImageName);


private:

	Core() = default;

	std::vector<MYImage*> LoadingImages; //��� �̹������� �����ͼ� �����Ұ�
	
};

