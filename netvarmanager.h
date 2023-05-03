#pragma once
#include "recv.h"
int GetOffset(const RecvTable* pRecvTable, const char* szNetvar);
int GetNetvarOffset(const char* szTable, const char* szNetvar);

#define NETVAR_FUNC(type, name, netvarOffset)	\
type name() {									\
	return *(type*)((int)this+netvarOffset);	\
}