#include "getinterface.h" 
HANDLE GetInterfaceAddress(const char* szModuleName, const char* szInterface) {
	typedef HANDLE(*protCreateInterface)(const char*, int*);
	const auto ci = (protCreateInterface)GetProcAddress(GetModuleHandle(szModuleName), "CreateInterface");
	return ci(szInterface, nullptr);
}