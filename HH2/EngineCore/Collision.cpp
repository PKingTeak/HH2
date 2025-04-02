#include "Collision.h"


std::map<Collision::Tag, std::set<Collision::Tag>> Collision::ColTag; //���� ���� 

void Collision::SettingTag(int _order, std::string _Name)
{
	ColTag[Tag::Actor].insert(Tag::Object);
	ColTag[Tag::Object].insert(Tag::Actor);
	//�±� ���� 
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
		//MessageBox(NULL,0, L"�浹Ȯ��", MB_OK);
		return true;
	}
	else
	{
		return false;
	}

	//����� �ٵ� �Ź� �̷��� �ؾ��ϳ�
//	int distance = sqrt((dx * dx) + (dy * dy)); //���� ������ �Ÿ�

	

}