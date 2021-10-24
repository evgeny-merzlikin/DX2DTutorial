#include <windows.h>
#include "Graphics.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY) { PostQuitMessage(0); return 0; }

	if (uMsg == WM_PAINT) 
	{
		graphics->BeginDraw();
		graphics->ClearScreen(0.0f, 0.0f, 0.5f);
		
		for (int i = 0; i < 1000; i++)
		{
			graphics->DrawCircle(rand()%800, rand()%600, rand()%100, 
				rand()%100/100.0f, 
				rand()%100/100.0f, 
				rand()%100/100.0f, 
				rand()%100/100.0f);
		}
		
		graphics->EndDraw();
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}




int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow)
{
	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));

	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = L"MainWindow";
	windowclass.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&windowclass);


	RECT rect = {0,0, 800, 600};
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowhandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MainWindow", L"DirectX Tute!", WS_OVERLAPPEDWINDOW, 100, 100, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0 );
	
	if (!windowhandle) return -1;
	
	graphics = new Graphics();
	if (!graphics->Init(windowhandle))
	{
		delete graphics;
		return -1;
	}

	ShowWindow(windowhandle, SW_NORMAL);

	MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		DispatchMessage(&message);
	}

	delete graphics;
	return 0;
}