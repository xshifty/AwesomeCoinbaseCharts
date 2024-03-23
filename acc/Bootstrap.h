#pragma once

#ifdef WIN32
#include <windows.h>
#endif

namespace AwesomeCoinbaseCharts {
    typedef struct BootstrapOptions {
        const char *title{};
        const int x = CW_USEDEFAULT;
        const int y = CW_USEDEFAULT;
        const int width = 800;
        const int height = 600;
        const unsigned long int backgroundColor = 0x306090;
        bool fullscreen = false;
#ifdef WIN32
        LPCSTR className{};
        HINSTANCE instance{};
#endif
    } *BootstrapOptionsPtr;

    class Bootstrap {
#ifdef WIN32
    private:
        HWND window;
        WNDCLASSEX windowClass{};
#endif

    public:
#ifdef WIN32
        static LRESULT CALLBACK WinProc(HWND win, UINT message, WPARAM wParam, LPARAM lParam);
#endif
        explicit Bootstrap(BootstrapOptionsPtr optionsPtr);
        void Run();
    };

    int BootstrapAndRun(BootstrapOptionsPtr optionsPtr);
}
