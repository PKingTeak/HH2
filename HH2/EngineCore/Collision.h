
#pragma once
#include "..\EngineBase\Transform.h"
#include<math.h>
#include<string>
#include<map>
#include<set>



class Collision : public Transform
{
public:

	enum class Tag //�±׸� ����ؼ� ����
	{
	BackGround = 0,
	Actor = 1,
	Object = 2

	};

public:
	inline Collision() : Transform(0, 0, 0, 0) {};

	Collision(int _x, int _y, int _width, int _height)
		: Transform(_x, _y, _width, _height)
	{
	}
	~Collision() = default;

	//ũ�⸦ �����;����� ������?
	//�ϴ� �����ڸ� ����ؼ� �浹ü�� ������̴�. 

	inline void SetCol(int _x, int _y, int _width, int _height)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;	
	}
	void SettingTag(int _order, std::string _Name);
	
	//bool FindTag(int _order);

	static bool AABB(Collision* _A, Collision* _B);
	

	inline void SettingTag(Tag _tag)
	{
		tag = _tag;
	}
	
	inline Tag GetTag()
	{
		return tag;
	}


	
protected:
	static std::map<Tag, std::set<Tag>> ColTag;
	
	Tag tag = Tag::BackGround;


};

