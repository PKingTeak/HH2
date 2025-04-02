#pragma once
#include "..\EnginePlatform\EngineWindow.h"
#include "..\EngineBase\MYImage.h"
#include "..\EngineBase\FileLoad.h"
#include "..\EngineBase\LeckChecker.h"
#include "..\EngineCore\Collision.h"

#include <gdiplus.h>
#include <iostream>
#include "Actor.h"


class Core
{
	
public:
	static Core& GetInstance()
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
	
	

	void Rendering();
	

	void Release();
	
	void Init(HINSTANCE hInstance);
	void Tick();
	//void Render(HDC hdc);
	void FindImage(std::string_view _ImageName);
	
	void CollCheck(Actor* _other);

	//스폰엑터 만들고 
	template<typename T>
	inline T* SpawnActor(const std::string_view _name)
	{
		T* NewActor = new T();
		
		Actor* SActor = static_cast<Actor*>(NewActor); //이거 어쩌피 엑터를 상속받아서 만들꺼잖아
		//근데 dynamic_cast를 사용해야하나?

		
		SActor->SetName(_name);
		SActor->SettingTag(Collision::Tag::Actor); //무조건 엑터일꺼니까?
		Actors.push_back(SActor);
		return SActor;
		//나중에 string으로 해서 해당엑터를 find 하고 그후 그 엑터의 세부설정을 해주는 방식을 사용해 볼것이다. 
		//오늘 질문할꺼 assert() 사용방법 잘 모름 
		
	}
	//



private:

	Core() = default;
	
	std::vector<MYImage*> LoadingImages; //모든 이미지들을 가져와서 저장할것
	std::vector<Actor*> Actors;
};

