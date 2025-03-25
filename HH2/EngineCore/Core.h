#pragma once
#include "..\EnginePlatform\EngineWindow.h"


class Core
{
	
public:
	Core() = default;
	~Core()
	{
		//ø©±‚ πª«ÿ¡‡æﬂ«“±Ó
	}


	Core(const Core& _Other) = delete;
	Core(Core&& _Other) noexcept = delete;
	Core& operator=(const Core& _Other) = delete;
	Core& operator=(Core&& _Other) noexcept = delete;
	
	
	
	

	void Init(HINSTANCE hInstance);
	void Tick();

};

