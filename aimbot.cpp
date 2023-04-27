#include "aimbot.h"

#ifdef _DEBUG
#include <iostream>
#define vPRINT(vector, msg) std::cout << vector.pitch << " " << vector.yaw << " " << vector.roll << " " << msg << "\n"
#define PRINT(msg) std::cout << msg << "\n"
#endif

void aimbotFeatures::doAimbot(CUserCMD* pCmd, CBaseEntity* pLocal) {
	getAimbotTarget(pCmd, pLocal);
}

CBaseEntity* aimbotFeatures::getAimbotTarget(CUserCMD* pCmd, CBaseEntity* pLocal) {
	Vector pLocalEyePosition = pLocal->getEyePosition();
	CBaseEntity* pEntity = interfaces::p_entitylist->getBaseEntity(2);
	if (!pEntity || !pEntity->isAlive())
		return nullptr;

	Vector pEntityPosition = pEntity->getOrigin();


	QAngle Angles = pEntityPosition.getForwardAngle(pLocalEyePosition);

	pCmd->viewangles = Angles;

	return nullptr;
}