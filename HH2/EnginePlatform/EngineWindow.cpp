#include "EngineWindow.h"

bool EngineWindow::WindowLive = true;
HINSTANCE EngineWindow::hInstance;

EngineWindow& EngineWindow::GetInstance()
{
	static EngineWindow instance;
	return instance; //�̱��� 
}


void EngineWindow::Init(HINSTANCE _hInstance)
{
	hInstance = _hInstance;
}

LRESULT CALLBACK EngineWindow::MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;              
		HDC hdc = BeginPaint(hwnd, &ps); 
		EndPaint(hwnd, &ps);
	}

	break;
	case WM_DESTROY:
	{
		WindowLive = false;
		break;
	}
	default:
		return DefWindowProcW(hwnd, uMsg, wParam, lParam);

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}




void EngineWindow::WindowOpen(std::string_view _WindowName, std::pair<int, int> _StartPos, std::pair<int, int> _Scale)
{
#pragma region BaseSettingWindow
	// ������ Ŭ���� ����
	const wchar_t  CLASS_NAME[] = L"MyWindow";  //char�� ��Ƽ����Ʈ �϶� ����ϰ� wchar_t�� �����ڵ� �϶� ����Ѵ�. char�� 1����Ʈ wchar_t�� 2����Ʈ�̸� �ѱ��� ǥ���Ҷ� ����Ѵ�. 
	WNDCLASS wc = { };
	wc.lpfnWndProc = MainWindowProc; // RectWIndowPROC�� ������ ���ν����� ����
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc);
	// ������ ����
	//�ϴ� CreateWindowEx()�� �������� MainWindowProc()�� ���µ� ������ �츮�� wc.hIcon ~ lpszMenuName ���� ������ ���߱� ������ �⺻������ �����찡 ���ֱ� ������
	// MainWindowProc() ���� DefWindowProc�� ���� ȣ��ȴ�. 
	HWND hwnd = CreateWindowEx(
		0,                              // Ȯ�� ������ ��Ÿ��
		CLASS_NAME,                     // ������ Ŭ���� �̸�
		L"MyWindow",                  // ������ ����
		WS_OVERLAPPEDWINDOW,            // ������ ��Ÿ��
		// ������ ũ��� ��ġ
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // �θ� ������ -> ������ �������� �����츦 ��ﶧ ����ϴµ�
		NULL,       // �޴�
		hInstance,  // �ν��Ͻ� �ڵ�
		NULL        // �߰� ���ø����̼� ������
	);

	if (hwnd == NULL)
	{
		return;
	}

#pragma endregion


	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	// �޽��� ����



}