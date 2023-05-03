#include "aimbot.h"
#include "interfaces.h"

#ifdef _DEBUG
#include <iostream>
#define V_PRINT(vector, msg) std::cout << (vector.pitch) << " " << (vector.yaw) << " " << (vector.roll) << " " << (msg) << "\n"
#define PRINT(msg) std::cout << (msg) << "\n" 
#endif

void aim_bot_features::DoAimBot(CUserCMD* pCmd, CBaseEntity* pLocal) {
	GetAimBotTarget(pCmd, pLocal);
}

CBaseEntity* aim_bot_features::GetAimBotTarget(CUserCMD* pCmd, CBaseEntity* pLocal) {
	const Vector pLocalEyePosition = pLocal->getEyePosition();
	CBaseEntity* pEntity = interfaces::pEntityList->getBaseEntity(2);
	if (!pEntity || pEntity->getLifeState())
		return nullptr;

	Vector pEntityPosition = pEntity->getOrigin();


	CONST QAngle angles = pEntityPosition.getForwardAngle(pLocalEyePosition);

	pCmd->viewangles = angles;

	return nullptr;
}