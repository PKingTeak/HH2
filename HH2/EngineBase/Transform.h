#pragma once
#include <Windows.h>
class Transform
{
public:
	Transform(int _x, int _y, int _width, int _height)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
	}
	inline void Move(int dx, int dy)
	{
		x += dx;
		y += dy;	
	}

	inline POINT GetCenter() const
	{
		//
		POINT center;
		center.x = x * (width / 2);
		center.y = y * (height / 2);
		return { center.x,center.y };
		//Áß½É ÁÂÇ¥ 
	}

	inline SIZE GetScale()const
	{
		return { x + width / 2,y + height / 2 };
	
	}
	
	
	inline void GetRect(RECT& rect) const
	{
	
		rect = { x, y, x + width, y + height };
	}


private:
	int x, y;	
	int width,height;
};

