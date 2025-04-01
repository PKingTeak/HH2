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

	//계산을 근데 매번 이렇게 해야하나
//	int distance = sqrt((dx * dx) + (dy * dy)); //두점 사이의 거리

	

}