
#pragma once
#include "..\EngineBase\Transform.h"

class Collision : public Transform
{
public:

	Collision(int _x, int _y, int _width, int _height)
		: Transform(_x, _y, _width, _height)
	{
		//부모 생성과 동시에 초기화 시킴
	}
	~Collision();

	//크기를 가져와야하지 않을까?

	
	void ColCheck()
	{
		//위치로 체크를 해야하나?

	}
	
private:
	bool isCol;



};

