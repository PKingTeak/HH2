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

	EngineWindow() = default; //�⺻������
	static LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	EngineWindow(HINSTANCE hInstance);
	
	
	std::pair<int, int> WindowStarPos;
	std::pair<int, int> WindowSize;

	HWND hWnd = nullptr;
	HDC wHdc = nullptr;
	static bool WindowLive; //������â �����ֳ�?
	static HINSTANCE hInstance; //�ν��Ͻ� �ڵ�

	MYImage* WImage = nullptr;
	

};

