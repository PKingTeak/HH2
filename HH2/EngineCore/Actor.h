#pragma once
#include"Collision.h"
#include"..\EngineBase\MYImage.h"
#include<list>
class Actor :public Collision
{

public:
	
	Actor();
	~Actor();

	void SetRender(MYImage* _Image);
	void SetCol(int _x, int _y, int _wid, int _hei);

private:
	Collision* ActorCol = nullptr;
	std::list<MYImage*> Render;
};

