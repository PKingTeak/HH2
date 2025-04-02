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
	//이미지 셋팅도 필요함
	void ChangeObject(Actor* _Other);


	inline void SetImage(MYImage* _Image)
	{
		
		ActorImage = _Image;
		//근데 삭제되면 안될듯 한데
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

