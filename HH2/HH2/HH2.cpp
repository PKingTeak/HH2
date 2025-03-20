#include <windows.h>

// 윈도우 프로시저 함수 선언
LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) //윈도우 메인함수 histance는 왜 값일까? 포인터로 주면 본체에도 영향이 가기 때문에 값으로 준다.
{
    // 윈도우 클래스 설정
    const wchar_t CLASS_NAME[] = L"MainWindow";
    WNDCLASS wc = { };
    wc.lpfnWndProc = MainWindowProc; // RectWIndowPROC를 윈도우 프로시저로 설정
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);
    // 윈도우 생성
    HWND hwnd = CreateWindowEx(
        0,                              // 확장 윈도우 스타일
        CLASS_NAME,                     // 윈도우 클래스 이름
        L"경택Window",    // 윈도우 제목
        WS_OVERLAPPEDWINDOW,            // 윈도우 스타일
        // 윈도우 크기와 위치
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // 부모 윈도우 -> 느낌이 여러개의 윈도우를 띄울때 사용하는듯
        NULL,       // 메뉴
        hInstance,  // 인스턴스 핸들
        NULL        // 추가 애플리케이션 데이터
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    // 메시지 루프

    MSG msg = { }; //메세지 구조체

	while (GetMessage(&msg, NULL, 0, 0)) //메세지가 있을때까지 계속 돌아감 -> 아마 다른창 볼때 멈추면 이상하니까 이렇게 한듯
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        //여기가 윈도우 TICK() 임 메세지 루프 
    }

    return 0;
}

// 윈도우 프로시저 함수 정의
LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0)); //일단 초록색 RGB(0,255,0)으로 설정
		SelectObject(hdc, hBrush);
		Rectangle(hdc, 100, 100, 200 , 200); //(100,100)부터 (200,200)까지 사각형 그리기   


        EndPaint(hwnd, &ps);
    }
    return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
