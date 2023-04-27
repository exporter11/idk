#include "hooks.h"
#include "interfaces.h"
#include "misc.h"
#include "aimbot.h"

bool __fastcall hooks::hkCreateMove(void* ecx, void* edx, float frametime, CUserCMD* pCmd) {
	CBaseEntity* pLocal = interfaces::p_entitylist->getBaseEntity(interfaces::p_engine->getLocalPlayer());

	if (!pLocal)
		return true;

	miscFeatures::doMiscFeatures(pCmd, pLocal);
	aimbotFeatures::doAimbot(pCmd, pLocal);

	return true;
}