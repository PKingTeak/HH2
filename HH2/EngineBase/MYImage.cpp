#include "MYImage.h"
#include <fstream>
#include<iostream>

MYImage::MYImage(const wchar_t* _Path, int _x, int _y)
{
	Image = Gdiplus::Image::FromFile(_Path);
}
MYImage::~MYImage()
{
	delete Image;
}



void MYImage::Draw(HDC& hdc , int _X, int _Y, int _wid, int _height)
{
	if (!Image)
	{
		return;
	}
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(Image, _X, _Y, _wid, _height);
}