#pragma once
#include<Windows.h>
class Image
{
public:
	Image(const wchar_t* _Path, int _x = 0, int _y =0); //파일 주소 필요한걸로 알고있음 사진 
	~Image();	


	void Draw(HDC& hdc);
	
	inline void Move(int dx, int dy)
	{
		X += dx;
		Y += dy;
	}

private:
	bool LoadImage(const wchar_t* _Path); //이미지 로드 해야함 
	

	HBITMAP hBitmap;
	int X, Y;
	int width, height;

	


};



/*
일단 이미지를 표현할때 필요한것들
1. 이미지를 로드해야함 -> 이미지 주소를 알아야함
2. 이미지를 그려야함 -> HDC를 알아야함
3. 이미지를 움직여야함 -> dx, dy
4. 이미지의 크기를 알아야함 -> width, height
5. 이미지의 위치를 알아야함  ->pos
6. 이미지의 해제를 해야함 ->delete
*/

