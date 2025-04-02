#include "Collision.h"


std::map<Collision::Tag, std::set<Collision::Tag>> Collision::ColTag; //전역 선언 

void Collision::SettingTag(int _order, std::string _Name)
{
	ColTag[Tag::Actor].insert(Tag::Object);
	ColTag[Tag::Object].insert(Tag::Actor);
	//태그 설정 
}



bool Collision::AABB(Collision* _A, Collision* _B)
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
		//MessageBox(NULL,0, L"충돌확인", MB_OK);
		return true;
	}
	else
	{
		return false;
	}

	//계산을 근데 매번 이렇게 해야하나
//	int distance = sqrt((dx * dx) + (dy * dy)); //두점 사이의 거리

	

}