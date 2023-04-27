#pragma once
#include "engineclient.h"
#include "getinterface.h"
#include "baseclient.h"
#include "gameevents.h"
#include "entity.h"
#include "patternScanner.h"
#define INTERFACE_ENGINE_CLIENT			"VEngineClient014"
#define INTERFACE_ENTITY_LIST_CLIENT	"VClientEntityList003"
#define INTERFACE_BASE_CLIENT_DLL		"VClient018"
#define INTERFACE_GAME_EVENTS_MANAGER2	"GAMEEVENTSMANAGER002"

#define PCLIENTSHAREDPATTERN "\x55\x8B\xEC\x8B\x0D \x8B\x01\x5D\xFF\x60\x30 XEND"

namespace interfaces {
	inline CEngineClient* p_engine;
	inline CBaseClientDLL* p_baseclient;
	inline IClientEntityList* p_entitylist;
	inline ClientModeShared* p_clientshared;

	inline void initInterfaces() {
		p_engine = (CEngineClient*)getInterfaceAddress("engine.dll", INTERFACE_ENGINE_CLIENT);
		p_baseclient = (CBaseClientDLL*)getInterfaceAddress("client.dll", INTERFACE_BASE_CLIENT_DLL);
		p_entitylist = (IClientEntityList*)getInterfaceAddress("client.dll", INTERFACE_ENTITY_LIST_CLIENT);
		patternScanner<DWORD*, DWORD*> pClientShared(PCLIENTSHAREDPATTERN, "client.dll");
		p_clientshared = *(ClientModeShared**)pClientShared.m_tValue;
	}
};