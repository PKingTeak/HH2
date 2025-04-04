#pragma once
#include "..\EnginePlatform\EngineWindow.h"
#include "..\EngineBase\MYImage.h"
#include "..\EngineBase\FileLoad.h"
#include "..\EngineBase\LeckChecker.h"
#include "..\EngineCore\Collision.h"

#include <gdiplus.h>
#include <iostream>
#include "Actor.h"
#include "Player.h"

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
		//컴포넌트 쓰는이유 상속하면 너무 생각할께 많음 
		// 엑터 콜리전 -> 생성 막하면 
		// 랜더링, 콜리전 상속으로 한거 
		//틱 할당 하는 <- 코어가 랜더러, 콜리전 돌린다. 
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
	
	void CollCheck();

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
		
		//강력한 장점 
		//assert로 어디서 터졌는지 100퍼 확인할수 있다. 
		//로그도 띄워 줄수 있다. 
		//cmd창으로 정확히 어디인지 알려줄 수 있다. 
	}
	//



private:

	Core() = default;
	
	std::vector<MYImage*> LoadingImages; //모든 이미지들을 가져와서 저장할것
	std::vector<Actor*> Actors;
	std::vector<Actor*> Object; //이거 임시용
};

