#include "misc.h"

void misc_features::DoMiscFeatures(CUserCMD* pCmd, CBaseEntity* pLocal) {
	AutoBunnyHop(pCmd, pLocal);
	FastDuck(pCmd);
}

void misc_features::FastDuck(CUserCMD* pCmd) {
	pCmd->buttons |= IN_BULLRUSH;
}

void misc_features::AutoBunnyHop(CUserCMD* pCmd, CBaseEntity* pLocal) {
	if (!(pCmd->buttons & IN_JUMP))
		return;

	if (pLocal->getFlags() & FL_ONGROUND)
		return;
		
		
	pCmd->buttons &= ~IN_JUMP;
}
