#include "Actor.h"

Actor::Actor(int _x, int _y, int _wid, int _hei)
{
	ActorCol = new Collision(_x, _y, _wid, _hei);
}


Actor ::~Actor()
{
	delete ActorCol;
	ActorCol = nullptr;
}


void SetRender(MYImage* _Image)
{
	//Core::GetInstanc().Render();
}