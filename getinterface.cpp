#include "getinterface.h" 
HANDLE getInterfaceAddress(const char* szModule, const char* szInterface) {
	typedef HANDLE(*protCreateInterface)(const char*, int*);
	protCreateInterface CI = (protCreateInterface)GetProcAddress(GetModuleHandle(szModule), "CreateInterface");
	return CI(szInterface, nullptr);
}