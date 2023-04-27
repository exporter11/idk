#pragma once
#include "recv.h"
int getOffset(RecvTable* recvtable, const char* szNetvar);
int getNetvarOffset(const char* szTable, const char* szNetvar);

#define netvar_func(type, name, netvaroffset)	\
type name() {									\
	return *(type*)((int)this+netvaroffset);	\
}