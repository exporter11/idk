#pragma once
#include "interfaces.h"
#include "entity.h"
#include "usercmd.h"
#include "math.h"

namespace aimbotFeatures {
	void doAimbot(CUserCMD* pCmd, CBaseEntity* pLocal);
	CBaseEntity* getAimbotTarget(CUserCMD* pCmd, CBaseEntity* pLocal);
};