#include "LeckChecker.h"

namespace LeckChecker
{
	void OutPutDebugText(std::string_view _DebugText)
	{
		std::string Text = _DebugText.data();
		Text += "\n";

		OutputDebugStringA(Text.c_str());
	}
}