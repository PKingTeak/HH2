#pragma once
#include"Collision.h"
#include"..\EngineBase\MYImage.h"
#include"Core.h"
#include<list>
class Actor :public Collision
{

public:
	Actor() = delete; //��ġ�� �������� �ʴ� ���ʹ� ���� �Ҽ� ���� ������ 

	Actor(int _x, int _y, int _wid, int _hei);
	~Actor();

	void SetRender(MYImage* _Image);

private:
	Collision* ActorCol = nullptr;
	std::list<MYImage*> Render;
};

