#pragma once
#include"Collision.h"
#include"..\EngineBase\MYImage.h"
#include<vector>
class Actor :public Collision
{
public:
	
	Actor();
	~Actor();

	void BeginPlay();
	
	

	void Render(HDC hdc);
	//이미지 셋팅도 필요함
	inline void SetImage(MYImage* _Image)
	{
		
		ActorImage = _Image;
		//근데 삭제되면 안될듯 한데
	}
	
	
private:
	
	
	MYImage* ActorImage = nullptr;
};

