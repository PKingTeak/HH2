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
	//ActorCol = new Collision();
	ActorCol->SetPos(_x, _y);
	ActorCol->SetScale(_wid, _hei);
}

void Actor::SetRender(MYImage* _Image)
{
	ActImages.push_back(_Image);
	

}

void Actor::Render(HDC hdc)
{
	if (!ActImages.empty())
	{
		ActImages[0]->Draw(hdc,this->x,this->y,this->width,this->height);//�ϴ� �����ϰ� �״��� Setindex���� �Լ��� ���� �̹��� ������ �غ��� .
	}
}


void Actor::BeginPlay()
{
	
}