#include "Actor.h"

Actor::Actor()
{
	tag = Tag::Actor;
}




Actor ::~Actor() 
{


	
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