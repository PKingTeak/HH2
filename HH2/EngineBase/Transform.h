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
		return { x + width / 2, y + height / 2 };
	}


	inline SIZE GetScale()const
	{
		return { x + width / 2,y + height / 2 };
	
	}
	
	
	inline void GetRect(RECT& rect) const
	{
	
		rect = { x, y, x + width, y + height };
	}

	inline void SetPos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	inline void SetScale(int _wid, int _hei)
	{
		width = _wid;
		height = _hei;
	}
	inline int Getwidth()
	{
		return width;
	}


	inline int Getheight()
	{
		return height;
	}

	inline int GetXpos()
	{
		return x;
	}
	inline int GetYPos()
	{
		return y;
	}
	
	
protected:
	int x, y;	
	int width,height;
};

