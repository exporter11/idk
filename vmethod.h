#pragma once
#define vMethod(type, name, args, args1, index, args2)		\
type name args {											\
	typedef type(__thiscall* pfn)args1;						\
	pfn fn = (pfn)((unsigned int**)this)[0][index];			\
	return fn args2;										\
}