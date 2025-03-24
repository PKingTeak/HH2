#include "MYImage.h"
#include <fstream>
#include<iostream>

MYImage::MYImage(const wchar_t* _Path, int _x, int _y)
{
	MessageBox(NULL, _Path, L"디버그 경로 확인", MB_OK);

	Image = Gdiplus::Image::FromFile(_Path);

	if (Image == nullptr || Image->GetLastStatus() != Gdiplus::Ok) {
		MessageBoxW(NULL, _Path, L"이미지 로딩 실패! 경로 확인!", MB_ICONERROR);
	}

	if (!Image || Image->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(NULL, L"이미지 로딩 실패!", L"오류", MB_OK | MB_ICONERROR);
	}
	Image = Gdiplus::Image::FromFile(_Path);

	X = _x;
	Y = _y;
	if (Image && Image->GetLastStatus() == Gdiplus::Ok)
	{
		width = Image->GetWidth()/2;
		height = Image->GetHeight()/2;
	}
	else
	{
		width = height = 0;
	}
}
MYImage::~MYImage()
{
	delete Image;
}

void MYImage::Draw(HDC& hdc)
{
	if (!Image)
	{
		return;
	}
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(Image, X, Y,width,height);
}