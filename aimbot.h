#pragma once
#include "entity.h"
#include "usercmd.h"

namespace aim_bot_features {
	void DoAimBot(CUserCMD* pCmd, CBaseEntity* pLocal);
	CBaseEntity* GetAimBotTarget(CUserCMD* pCmd, CBaseEntity* pLocal);
};