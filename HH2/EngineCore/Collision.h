
#pragma once
#include "..\EngineBase\Transform.h"

class Collision : public Transform
{
public:

	Collision(int _x, int _y, int _width, int _height)
		: Transform(_x, _y, _width, _height)
	{
		//�θ� ������ ���ÿ� �ʱ�ȭ ��Ŵ
	}
	~Collision();

	//ũ�⸦ �����;����� ������?

	
	void ColCheck()
	{
		//��ġ�� üũ�� �ؾ��ϳ�?

	}
	
private:
	bool isCol;



};

