#pragma once
#include<Windows.h>
#include <gdiplus.h>
#include<vector>
#pragma comment(lib, "gdiplus.lib")
class MYImage
{
public:
	MYImage(const wchar_t* _Path, int _x = 0, int _y =0); //파일 주소 필요한걸로 알고있음 사진 
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

	//배열 사용해서 이미지 여러개 저장해볼꺼임
	std::vector<Gdiplus::Image*> Images;


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

