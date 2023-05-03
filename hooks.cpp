#include "hooks.h"
#include "interfaces.h"
#include "misc.h"
#include "aimbot.h"
#include <iostream>
bool __fastcall hooks::CreateMoveHk(void* ecx, void* edx, float frametime, CUserCMD* pCmd) {
	CBaseEntity* pLocal = interfaces::pEntityList->getBaseEntity(interfaces::pEngineClient->getLocalPlayer());

	if (!pLocal)
		return true;

	void* stack;
	__asm mov stack, esp;

	//std::cout << stack << '\n';

	misc_features::DoMiscFeatures(pCmd, pLocal);
	aim_bot_features::DoAimBot(pCmd, pLocal);

	return true;
}