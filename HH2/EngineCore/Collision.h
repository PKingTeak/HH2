
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

	//ũ�⸦ �����;����� ������?
	//�ϴ� �����ڸ� ����ؼ� �浹ü�� ������̴�. 

	
	void ColCheck()
	{
		//��ġ�� üũ�� �ؾ��ϳ�?

	}
	
private:


};

