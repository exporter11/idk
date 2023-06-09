#pragma once
#include "vmethod.h"
#include "math.h"
#include "netvarmanager.h"

#define	FL_ONGROUND				(1<<0)	// At rest / on the ground
#define FL_DUCKING				(1<<1)	// Player flag -- Player is fully crouched
#define FL_ANIMDUCKING			(1<<2)	// Player flag -- Player is in the process of crouching or uncrouching but could be in transition
#define	FL_WATERJUMP			(1<<3)	// player jumping out of water
#define FL_ONTRAIN				(1<<4) // Player is _controlling_ a train, so movement commands should be ignored on client during prediction.
#define FL_INRAIN				(1<<5)	// Indicates the entity is standing in rain
#define FL_FROZEN				(1<<6) // Player is frozen for 3rd person camera
#define FL_ATCONTROLS			(1<<7) // Player can't move, but keeps key inputs for controlling another entity
#define	FL_CLIENT				(1<<8)	// Is a player
#define FL_FAKECLIENT			(1<<9)	// Fake client, simulated server side; don't send network messages to them
#define	FL_INWATER				(1<<10)	// In water
#define PLAYER_FLAG_BITS		11
#define	FL_FLY					(1<<11)	// Changes the SV_Movestep() behavior to not need to be on ground
#define	FL_SWIM					(1<<12)	// Changes the SV_Movestep() behavior to not need to be on ground (but stay in water)
#define	FL_CONVEYOR				(1<<13)
#define	FL_NPC					(1<<14)
#define	FL_GODMODE				(1<<15)
#define	FL_NOTARGET				(1<<16)
#define	FL_AIMTARGET			(1<<17)	// set if the crosshair needs to aim onto the entity
#define	FL_PARTIALGROUND		(1<<18)	// not all corners are valid
#define FL_STATICPROP			(1<<19)	// Eetsa static prop!		
#define FL_GRAPHED				(1<<20) // worldgraph has this ent listed as something that blocks a connection
#define FL_GRENADE				(1<<21)
#define FL_STEPMOVEMENT			(1<<22)	// Changes the SV_Movestep() behavior to not do any processing
#define FL_DONTTOUCH			(1<<23)	// Doesn't generate touch functions, generates Untouch() for anything it was touching when this flag was set
#define FL_BASEVELOCITY			(1<<24)	// Base velocity has been applied this frame (used to convert base velocity into momentum)
#define FL_WORLDBRUSH			(1<<25)	// Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something)
#define FL_OBJECT				(1<<26) // Terrible name. This is an object that NPCs should see. Missiles, for example.
#define FL_KILLME				(1<<27)	// This entity is marked for death -- will be freed by game DLL
#define FL_ONFIRE				(1<<28)	// You know...
#define FL_DISSOLVING			(1<<29) // We're dissolving!
#define FL_TRANSRAGDOLL			(1<<30) // In the process of turning into a client side ragdoll.
#define FL_UNBLOCKABLE_BY_PLAYER (1<<31) // pusher that can't be blocked by the player
#define FL_FREEZING				(1<<32) // We're becoming frozen!


class IClientUnknown;
class IClientRenderable;
class IClientEntity;
class CBaseEntity;

namespace netvars {
	inline int offHealth;
	inline int offFlags;
	inline int offOrigin;
	inline int offViewOffset;
	inline int offLifestate;

	inline void InitNetvars() {
		offHealth = GetNetvarOffset("DT_BasePlayer", "m_iHealth");
		offFlags = GetNetvarOffset("DT_BasePlayer", "m_fFlags");
		offOrigin = GetNetvarOffset("DT_BaseEntity", "m_vecOrigin");
		offViewOffset = GetNetvarOffset("DT_BasePlayer", "m_vecViewOffset[0]");
		offLifestate = GetNetvarOffset("DT_BasePlayer", "m_lifestate");
	}
}

class IClientNetworkable {
public:
	virtual IClientUnknown* getIClientUnknown() = 0;
};
class IClientUnknown {
public:
	vMethod(IClientNetworkable*, getClientNetworkable, (), (void*), 4, (this))
	vMethod(IClientRenderable*, getClientRenderable, (), (void*), 5, (this))
	vMethod(IClientEntity*, getCLientEntity, (), (void*), 6, (this))
	vMethod(CBaseEntity*, getBaseEntity, (), (void*), 7, (this))
};
class IClientRenderable {
public:

};
class IClientEntity {
public:


};
class CBaseEntity {
public:
	NETVAR_FUNC(int, getHealth, netvars::offHealth)
	NETVAR_FUNC(unsigned int, getFlags, netvars::offFlags)
	NETVAR_FUNC(Vector, getOrigin, netvars::offOrigin)
	NETVAR_FUNC(Vector, getViewOffset, netvars::offViewOffset)
	NETVAR_FUNC(bool, getLifeState, netvars::offLifestate)

	Vector getEyePosition() {
		return getOrigin() + getViewOffset();
	}
};

class IClientEntityList {
public:
	virtual IClientNetworkable* getClientNetworkable(int entNum) = 0;
	CBaseEntity* getBaseEntity(int entNum) {
			IClientNetworkable* clientNetworkable = getClientNetworkable(entNum);
			if (!clientNetworkable)
				return nullptr;

			IClientUnknown* clientUnknown = clientNetworkable->getIClientUnknown();
			if (!clientUnknown)
				return nullptr;

			return clientUnknown->getBaseEntity();
	}
};
