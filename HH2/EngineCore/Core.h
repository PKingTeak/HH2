#pragma once
#include "..\EnginePlatform\EngineWindow.h"
#include "..\EngineBase\MYImage.h"
#include "..\EngineBase\FileLoad.h"

#include <gdiplus.h>
#include <iostream>
#include "Actor.h"

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

	std::vector<MYImage*> LoadingImages; //모든 이미지들을 가져와서 저장할것
	std::vector<Actor*> Actors;
};

