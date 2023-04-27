#include "misc.h"

void miscFeatures::doMiscFeatures(CUserCMD* pCmd, CBaseEntity* pLocal) {
	autoBunnyHop(pCmd, pLocal);
	fastDuck(pCmd);
}

void miscFeatures::fastDuck(CUserCMD* pCmd) {
	pCmd->buttons |= IN_BULLRUSH;
}

void miscFeatures::autoBunnyHop(CUserCMD* pCmd, CBaseEntity* pLocal) {
	if (!(pCmd->buttons & IN_JUMP))
		return;

	if (pLocal->getFlags() & FL_ONGROUND)
		return;
		
		
	pCmd->buttons &= ~IN_JUMP;
}
