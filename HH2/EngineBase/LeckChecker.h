#pragma once
#include<Windows.h>
#include<string>
#include<string_view>
#include<assert.h>


namespace LeckChecker
{
	#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	#define MsgBoxAssert(Value) \
	std::string ErrorText = std::string(Value); \
	MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

	void OutPutDebugText(std::string_view _DebugText);
}
