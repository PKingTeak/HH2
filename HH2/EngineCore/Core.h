#pragma once
#include "..\EnginePlatform\EngineWindow.h"
#include "..\EngineBase\MYImage.h"

class Core
{
	
public:
	Core() = default;
	~Core()
	{
		//여기 뭘해줘야할까
	}


	Core(const Core& _Other) = delete;
	Core(Core&& _Other) noexcept = delete;
	Core& operator=(const Core& _Other) = delete;
	Core& operator=(Core&& _Other) noexcept = delete;
	
	
	
	

	void Init(HINSTANCE hInstance);
	void Tick();

private:
	std::vector<MYImage*> LoadingImages; //목록 저장 
};

