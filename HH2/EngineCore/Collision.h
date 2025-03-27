
#pragma once
#include "..\EngineBase\Transform.h"

class Collision : public Transform
{
public:
	inline Collision() : Transform(0, 0, 0, 0) {};
	Collision(int _x, int _y, int _width, int _height)
		: Transform(_x, _y, _width, _height)
	{
	}
	~Collision() = default;

	//크기를 가져와야하지 않을까?
	//일단 생성자를 사용해서 충돌체를 만들것이다. 

	
	void ColCheck()
	{
		//위치로 체크를 해야하나?

	}
	
private:


};

