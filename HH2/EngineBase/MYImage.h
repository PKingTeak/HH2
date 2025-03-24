#pragma once
#include<Windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
class MYImage
{
public:
	MYImage(const wchar_t* _Path, int _x = 0, int _y =0); //���� �ּ� �ʿ��Ѱɷ� �˰����� ���� 
	~MYImage();	


	void Draw(HDC& hdc);
	
	inline void Move(int dx, int dy)
	{
		X += dx;
		Y += dy;
	}

private:
	

	Gdiplus::Image* Image; 
	int X, Y;
	int width, height;

	


};



/*
�ϴ� �̹����� ǥ���Ҷ� �ʿ��Ѱ͵�
1. �̹����� �ε��ؾ��� -> �̹��� �ּҸ� �˾ƾ���
2. �̹����� �׷����� -> HDC�� �˾ƾ���
3. �̹����� ���������� -> dx, dy
4. �̹����� ũ�⸦ �˾ƾ��� -> width, height
5. �̹����� ��ġ�� �˾ƾ���  ->pos
6. �̹����� ������ �ؾ��� ->delete
*/

