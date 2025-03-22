#include "Image.h"


Image::Image(const wchar_t* _Path, int _x, int _y)
{
	hBitmap = (HBITMAP)LoadImage(NULL, _Path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	BITMAP bitmap;
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	width = bitmap.bmWidth;
	height = bitmap.bmHeight;
	X = _x;
	Y = _y;
}

void Image::Draw(HDC& hdc)
{
	HDC MemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);
	BitBlt(hdc, X, Y, width, height, MemDC, 0, 0, SRCCOPY);
	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}