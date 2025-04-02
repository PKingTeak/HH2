#include "Actor.h"


Actor::Actor()
{
	tag = Tag::Actor;
}

Actor ::~Actor() 
{


	
}
void Actor::ChangeObject(Actor* _Other)
{
	bool isCon = this->AABB(this, _Other);
	if (isCon == true)
	{
		_Other->SetImage(ActorImage);
	}
	
}


void Actor::Render(HDC hdc)
{
	if(ActorImage != nullptr)
	{
		ActorImage->Draw(hdc,this->x,this->y,this->width,this->height);//�ϴ� �����ϰ� �״��� Setindex���� �Լ��� ���� �̹��� ������ �غ��� .
		
		
	}
}


void Actor::BeginPlay()
{
	
}