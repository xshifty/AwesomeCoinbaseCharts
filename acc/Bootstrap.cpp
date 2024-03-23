#include "Bootstrap.h"

namespace AwesomeCoinbaseCharts {
#ifdef WIN32
    LRESULT Bootstrap::WinProc(HWND win, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }

        return DefWindowProc(win, message, wParam, lParam);
    }
#endif

    Bootstrap::Bootstrap(BootstrapOptionsPtr optionsPtr) {
        int nWidth = optionsPtr->width;
        int nHeight = optionsPtr->height;
        int nX = optionsPtr->x;
        int nY = optionsPtr->y;

#ifdef WIN32
        DWORD dwStyle = WS_MAXIMIZE | WS_OVERLAPPEDWINDOW;

        ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

        windowClass.cbSize = sizeof(WNDCLASSEX);
        windowClass.style = CS_HREDRAW | CS_VREDRAW;
        windowClass.lpfnWndProc = WinProc;
        windowClass.hInstance = optionsPtr->instance;
        windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
        windowClass.lpszClassName = optionsPtr->className;
        windowClass.hbrBackground = (HBRUSH) CreateSolidBrush(
                RGB(
                        optionsPtr->backgroundColor >> 16 & 0xff,
                        optionsPtr->backgroundColor >> 8 & 0xff,
                        optionsPtr->backgroundColor & 0xff
                )
        );

        RegisterClassEx(&windowClass);

        if (optionsPtr->fullscreen) {
            nX = 0;
            nY = 0;
            nWidth = GetSystemMetrics(SM_CXSCREEN);
            nHeight = GetSystemMetrics(SM_CYSCREEN);
            dwStyle = WS_POPUP;
        }

        window = CreateWindowEx(NULL,
                                optionsPtr->className,
                                optionsPtr->title,
                                 WS_VISIBLE | dwStyle,
                                nX,
                                nY,
                                nWidth,
                                nHeight,
                                nullptr,
                                nullptr,
                                optionsPtr->instance,
                                nullptr);

        if (window == nullptr) {
            MessageBoxA(nullptr, "Unable to initialize the main window", "Error", 0);
        }
#endif
    }

    void Bootstrap::Run() {
#ifdef WIN32
        ShowWindow(window, SW_SHOW);

        MSG msg;

        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
#endif
    }

    int BootstrapAndRun(BootstrapOptionsPtr optionsPtr) {
        auto bs = new Bootstrap(optionsPtr);
        bs->Run();

        return 0;
    }
}
