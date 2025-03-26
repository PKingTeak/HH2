#pragma once

#include <windows.h>
#include <string>
#include <memory>
#include "..\EngineBase\MYImage.h"


class EngineWindow
{
public:
	static EngineWindow& GetInstance();
	

	void Init(HINSTANCE hInstance);

	EngineWindow(EngineWindow&&) = delete;
	EngineWindow(const EngineWindow&) = delete;
	EngineWindow& operator=(const EngineWindow&) = delete;
	EngineWindow& operator=(EngineWindow&& _Other) noexcept = delete;


	void WindowOpen(std::string_view _WindowName, std::pair<int,int> _StartPos, std::pair<int,int> _Scale);

	inline static bool IsWindowLive()
	{
		return WindowLive;
	}
	
	HDC GetHDC() const;
	

private:

	inline void SetHDC(HDC _Hdc)
	{
		wHdc = _Hdc;
	}

	EngineWindow() = default; //기본생성자
	static LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	EngineWindow(HINSTANCE hInstance);
	
	
	std::pair<int, int> WindowStarPos;
	std::pair<int, int> WindowSize;

	HWND hWnd = nullptr;
	HDC wHdc = nullptr;
	static bool WindowLive; //윈도우창 켜져있나?
	static HINSTANCE hInstance; //인스턴스 핸들

	MYImage* WImage = nullptr;
	

};

