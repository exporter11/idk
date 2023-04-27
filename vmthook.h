#pragma once
#include <Windows.h>
class vmthook {
private:
	DWORD** m_pFunction;
	DWORD* m_uiOriginal;
public:
	vmthook(void* p_class, DWORD index, DWORD* replacer);
	~vmthook();
};

