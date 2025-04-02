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

	//�������� ����� 
	template<typename T>
	inline T* SpawnActor(const std::string_view _name)
	{
		T* NewActor = new T();
		
		Actor* SActor = static_cast<Actor*>(NewActor); //�̰� ��¼�� ���͸� ��ӹ޾Ƽ� ���鲨�ݾ�
		//�ٵ� dynamic_cast�� ����ؾ��ϳ�?

		
		SActor->SetName(_name);
		SActor->SettingTag(Collision::Tag::Actor); //������ �����ϲ��ϱ�?
		Actors.push_back(SActor);
		return SActor;
		//���߿� string���� �ؼ� �ش翢�͸� find �ϰ� ���� �� ������ ���μ����� ���ִ� ����� ����� �����̴�. 
		//���� �����Ҳ� assert() ����� �� �� 
		
	}
	//



private:

	Core() = default;
	
	std::vector<MYImage*> LoadingImages; //��� �̹������� �����ͼ� �����Ұ�
	std::vector<Actor*> Actors;
};

