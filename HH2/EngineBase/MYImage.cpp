#include "MYImage.h"


MYImage::MYImage(const wchar_t* _Path, int _x, int _y)
{
	image = Gdiplus::Image::FromFile(_Path); //주소를 넣어줄꺼임

	X = _x;
	Y = _y;
	
	if (image && image->GetLastStatus() == Gdiplus::Ok)
	{
	width = image->GetWidth();
	height = image->GetHeight();
	}
	else
	{
		width = 0;
		height =0;
	}
}
MYImage::~MYImage()
{
	delete image;
}

void MYImage::Draw(HDC& hdc)
{
	if (!image)
	{
		return;
	}
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(image, X, Y);
}