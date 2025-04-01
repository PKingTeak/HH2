#include "MYImage.h"
#include <fstream>
#include<iostream>

MYImage::MYImage(const wchar_t* _Path, int _x, int _y)
{

	Image = Gdiplus::Image::FromFile(_Path);

	/*
	MessageBox(NULL, _Path, L"디버그 경로 확인", MB_OK);
	if (Image == nullptr || Image->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBoxW(NULL, _Path, L"이미지 로딩 실패! 경로 확인!", MB_ICONERROR);
	}

	if (!Image || Image->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(NULL, L"이미지 로딩 실패!", L"오류", MB_OK | MB_ICONERROR);
	}
	*/
	//Image = Gdiplus::Image::FromFile(_Path);


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