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
	
	

	void Render(HDC hdc);
	//�̹��� ���õ� �ʿ���
	inline void SetImage(MYImage* _Image)
	{
		
		ActorImage = _Image;
		//�ٵ� �����Ǹ� �ȵɵ� �ѵ�
	}
	
	
private:
	
	
	MYImage* ActorImage = nullptr;
};

