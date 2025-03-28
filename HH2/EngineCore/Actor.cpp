#include "Actor.h"

Actor::Actor()
{
	
}


Actor ::~Actor()
{
	delete ActorCol;
	ActorCol = nullptr;
}
void Actor::SetCol(int _x, int _y, int _wid, int _hei)
{
	ActorCol = new Collision();
	ActorCol->SetPos(_x, _y);
	ActorCol->SetScale(_wid, _hei);
}

void Actor::SetRender(MYImage* _Image)
{
	Render.push_back(_Image);
	

}


void Actor::BeginPlay()
{
	
}