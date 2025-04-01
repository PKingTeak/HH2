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
		ActorImage->Draw(hdc,this->x,this->y,this->width,this->height);//일단 진행하고 그다음 Setindex같은 함수를 만들어서 이미지 변경을 해보자 .
		
		
	}
}


void Actor::BeginPlay()
{
	
}