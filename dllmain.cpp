#include <Windows.h>
#include <iostream>
#include "interfaces.h"
#include "hook.h"
#include "hooks.h"

void ExecuteHack() {
	std::cout << "Waiting for game to fully initialize\n";
	while (!GetModuleHandle("serverbrowser.dll"));
	std::cout << "Initialized!\n";
	Sleep(250);

	interfaces::InitInterfaces();
	netvars::InitNetvars();

	std::cout << interfaces::pClientModeShared << '\n';
	std::cout << netvars::offHealth << '\n';
	{
		CVmtHook createMoveHook(interfaces::pClientModeShared, 24, (DWORD*)hooks::CreateMoveHk);
		while (!GetAsyncKeyState(VK_END));
	}
}

void HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	ExecuteHack();

	if (f)
		fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, DLL_THREAD_DETACH);
}

BOOL WINAPI DllMain(
	HMODULE hModule, // handle to DLL module
	DWORD fdwReason, // reason for calling function
	LPVOID lpvReserved) // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		{
			if (CONST HANDLE hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, nullptr))
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

	default:
		break;
	}

	return TRUE; // Successful DLL_PROCESS_ATTACH.
}
