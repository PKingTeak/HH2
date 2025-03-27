#pragma once
#include"Collision.h"
#include"..\EngineBase\MYImage.h"
#include"Core.h"
#include<list>
class Actor :public Collision
{

public:
	Actor() = delete; //위치가 존재하지 않는 엑터는 존재 할수 없기 때문에 

	Actor(int _x, int _y, int _wid, int _hei);
	~Actor();

	void SetRender(MYImage* _Image);

private:
	Collision* ActorCol = nullptr;
	std::list<MYImage*> Render;
};

