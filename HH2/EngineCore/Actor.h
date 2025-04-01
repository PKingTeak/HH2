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
	void SetRender(MYImage* _Image);
	void SetCol(int _x, int _y, int _wid, int _hei);


	void Render(HDC hdc);

private:
	Collision* ActorCol = nullptr;
	std::vector<MYImage*> ActImages;
};

