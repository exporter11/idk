#pragma once
#include "engineclient.h"
#include "getinterface.h"
#include "baseclient.h"
#include "entity.h"
#include "patternScanner.h"
#define INTERFACE_ENGINE_CLIENT			"VEngineClient014"
#define INTERFACE_ENTITY_LIST_CLIENT	"VClientEntityList003"
#define INTERFACE_BASE_CLIENT_DLL		"VClient018"
#define INTERFACE_GAME_EVENTS_MANAGER2	"GAMEEVENTSMANAGER002"

#define PCLIENTSHAREDPATTERN "\x55\x8B\xEC\x8B\x0D \x8B\x01\x5D\xFF\x60\x30 XEND"

namespace interfaces {
	inline CEngineClient* pEngineClient;
	inline CBaseClientDll* pBaseClientDll;
	inline IClientEntityList* pEntityList;
	inline ClientModeShared* pClientModeShared;

	inline void InitInterfaces() {
		pEngineClient = (CEngineClient*)GetInterfaceAddress("engine.dll", INTERFACE_ENGINE_CLIENT);
		pBaseClientDll = (CBaseClientDll*)GetInterfaceAddress("client.dll", INTERFACE_BASE_CLIENT_DLL);
		pEntityList = (IClientEntityList*)GetInterfaceAddress("client.dll", INTERFACE_ENTITY_LIST_CLIENT);
		const CPatternScanner<DWORD*, DWORD*> pClientShared(PCLIENTSHAREDPATTERN, "client.dll");
		pClientModeShared = *(ClientModeShared**)pClientShared.m_tValue;
	}
};