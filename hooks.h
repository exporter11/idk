#pragma once
#include "usercmd.h"
namespace hooks {
	bool __fastcall hkCreateMove(void* ecx, void* edx, float frametime, CUserCMD* p_cmd);
}