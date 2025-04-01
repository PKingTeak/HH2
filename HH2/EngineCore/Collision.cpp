#include "Collision.h"


bool AABB(Collision* _A, Collision* _B)
{
	POINT Apoint = _A->GetCenter();
	POINT BPoint = _B->GetCenter();


	int dx = abs(Apoint.x - BPoint.x);
	int dy = abs(Apoint.y- BPoint.y);
	

	int HwidthA = _A->Getwidth();
	int HheightA = _A->Getheight();

	int HwidthB = _B->Getwidth();
	int HheightB = _B->Getheight();


	if (dx <= HwidthA + HwidthB && dy <= HheightA + HheightB)
	{
		return true;
	}
	else
	{
		return false;
	}

	//����� �ٵ� �Ź� �̷��� �ؾ��ϳ�
//	int distance = sqrt((dx * dx) + (dy * dy)); //���� ������ �Ÿ�

	

}