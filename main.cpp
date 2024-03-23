#include "acc/Bootstrap.h"

namespace acc = AwesomeCoinbaseCharts;

acc::BootstrapOptions buildOptions();

#ifdef WIN32
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow) {
    auto opts = buildOptions();
    {
        opts.className = "MainAppWindow";
        opts.instance = instance;
    }
    return BootstrapAndRun(&opts);
}
#else
int main(int argc, char **argv) {
    auto opts = buildOptions();
    return BootstrapAndRun(&opts);
}
#endif

acc::BootstrapOptions buildOptions() {
    return acc::BootstrapOptions{
            .title = "Awesome Coinbase Charts",
            .backgroundColor = 0x303030,
            .fullscreen = true,
    };
}
