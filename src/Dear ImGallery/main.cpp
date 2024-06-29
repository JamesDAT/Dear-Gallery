#include <iostream>
#ifdef USE_WINDOWS
#include <Windows.h>
#endif

#ifdef USE_WINDOWS
int WINAPI WinMain(
    HINSTANCE hInstance,      
    HINSTANCE hPrevInstance,  
    LPSTR lpCmdLine,          
    int nCmdShow              
) {
    MessageBox(NULL, L"Hello, World!", L"Gallery Test Box", MB_OK);

    return 0;
}
#endif
