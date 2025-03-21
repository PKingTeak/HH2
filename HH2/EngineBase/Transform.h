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
	
	inline void GetRect(RECT& rect) const
	{
	
		rect = { x, y, x + width, y + height };
	}


private:
	int x, y;	
	int width,height;
};

