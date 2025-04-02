#pragma once
#include"Collision.h"
#include"..\EngineBase\MYImage.h"
#include<string>
#include<vector>
class Actor :public Collision
{
public:
	
	Actor();
	~Actor();

	void BeginPlay();
	
	void Render(HDC hdc);
	//�̹��� ���õ� �ʿ���
	void ChangeObject(Actor* _Other);


	inline void SetImage(MYImage* _Image)
	{
		
		ActorImage = _Image;
		//�ٵ� �����Ǹ� �ȵɵ� �ѵ�
	}
	inline MYImage* GetImage()
	{
		return ActorImage;
	}


	inline void SetName(std::string_view _Name)
	{
		Name = _Name;
	}
private:
	
	std::string Name;
	MYImage* ActorImage = nullptr;
};

