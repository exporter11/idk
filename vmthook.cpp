#include "vmthook.h"
vmthook::vmthook(void* p_class, DWORD index, DWORD* replacer) {
	m_pFunction = 0;
	m_uiOriginal = 0;

	DWORD** pFunction = ((DWORD***)p_class)[0] + index;

	if (!pFunction)
		return;

	m_pFunction = pFunction;
	m_uiOriginal = *pFunction;

	DWORD op;
	VirtualProtect(pFunction, sizeof(DWORD**), PAGE_EXECUTE_READWRITE, &op);
	*pFunction = replacer;
	VirtualProtect(pFunction, sizeof(DWORD**), op, &op);
}

vmthook::~vmthook() {
	if (!(m_pFunction && m_uiOriginal))
		return;
	
	DWORD op;
	VirtualProtect(m_pFunction, sizeof(DWORD*), PAGE_EXECUTE_READWRITE, &op);
	*m_pFunction = m_uiOriginal;
	VirtualProtect(m_pFunction, sizeof(DWORD*), op, &op);
}