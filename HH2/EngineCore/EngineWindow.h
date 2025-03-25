#pragma once

#include <windows.h>
class EngineWindow
{
public:
	static EngineWindow& GetInstance();
	

	void Init(HINSTANCE hInstance, int nCmdShow);

	EngineWindow(EngineWindow&&) = delete;
	EngineWindow(const EngineWindow&) = delete;
	EngineWindow& operator=(const EngineWindow&) = delete;
	EngineWindow& operator=(EngineWindow&& _Other) noexcept = delete;


private:

	EngineWindow() = default; //기본생성자

	EngineWindow(HINSTANCE hInstance, int nCmdShow);

	HWND hWnd = nullptr;

	

};

