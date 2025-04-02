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
	POINT Bpoint = _B->GetCenter();


	int dx = abs(Apoint.x - Bpoint.x);
	int dy = abs(Apoint.y- Bpoint.y);
	

	int Aleft = Apoint.x -_A->Getwidth()/2;
	int ARight = Apoint.x + _A->Getwidth() / 2;
	int ATop = Apoint.y - _A->Getheight() / 2;
	int ABottom = Apoint.y + _A->Getheight() / 2;


	
	int Bleft = Bpoint.x - _B->Getwidth() / 2;
	int BRight = Bpoint.x + _B->Getwidth() / 2;
	int BTop = Bpoint.y - _B->Getheight() / 2;
	int BBottom = Bpoint.y + _B->Getheight() / 2;
	
	bool ABhorizon = Aleft<=BRight && ARight  >=Bleft;
	bool ABperpen = ATop <= BBottom && ABottom >= BTop;

	if (ABhorizon && ABperpen)
	{
		return true;
	}
	else
	{
		return false;
	}

	

	

}