#include <iostream>
#ifdef USE_WINDOWS
#include <Windows.h>
#endif

// std
#include <memory>

// project headers
#include "Core/Window.h"

#ifdef USE_WINDOWS
int WINAPI WinMain(
    HINSTANCE hInstance,      
    HINSTANCE hPrevInstance,  
    LPSTR lpCmdLine,          
    int nCmdShow              
) {
    std::unique_ptr<Gallery::Window> pWindow(new Gallery::Window);
    pWindow->Run();

    return 0;
}
#endif
