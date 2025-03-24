#pragma once
#include<Windows.h>
#include <gdiplus.h>
#include<vector>
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

	inline void SetImages(const wchar_t* _FilePath)
	{
		Images.push_back(Image);
	}

private:
	

	Gdiplus::Image* Image; 
	int X, Y;
	int width, height;

	//�迭 ����ؼ� �̹��� ������ �����غ�����
	std::vector<Gdiplus::Image*> Images;


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

