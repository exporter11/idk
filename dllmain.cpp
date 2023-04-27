#include <Windows.h>
#include <iostream>
#include "interfaces.h"
#include "netvarmanager.h"
#include "vmthook.h"
#include "hooks.h"

void hackThread(HMODULE hModule) {

    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
   
    std::cout << "Waiting for game to fully initialize\n";
    while (!GetModuleHandle("serverbrowser.dll"));
    std::cout << "Initialized!\n";
    Sleep(250);
    system("cls");

    interfaces::initInterfaces();
    netvars::initNetvars();

    std::cout << interfaces::p_clientshared;

    {
        vmthook createmovehook(interfaces::p_clientshared, 24, (DWORD*)hooks::hkCreateMove);
        while (!GetAsyncKeyState(VK_END));
    }
     
    if (f)
        fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, DLL_THREAD_DETACH);
}

BOOL WINAPI DllMain(
    HMODULE hModule,        // handle to DLL module
    DWORD fdwReason,        // reason for calling function
    LPVOID lpvReserved)     // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
    {
        HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hackThread, hModule, 0, 0);
        if (hThread)
            CloseHandle(hThread);

        break;
    }

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }

    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}