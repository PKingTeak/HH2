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


private:

	Core() = default;

	std::vector<MYImage*> LoadingImages; //��� �̹������� �����ͼ� �����Ұ�
	//std::vector<Collision*? Collisions; //�浹ü ������ ���� 
};

