#pragma once

#include "getinterface.h"
#include "vMethod.h"
#include "math.h"
#include "netchannelinfo.h"

#define MAX_PLAYER_NAME_LENGTH		128
#define SIGNED_GUID_LEN				32
#define MAX_CUSTOM_FILES			4

struct PlayerInfo
{
	// version for future compatibility
	UINT64			version;
	// network x uid
	UINT64			xuid;
	// scoreboard information
	char			name[MAX_PLAYER_NAME_LENGTH];
	// local server user ID, unique while server is running
	int				userId;
	// global unique player identifier
	char			guid[SIGNED_GUID_LEN + 1];
	// friends identification number
	unsigned int			friendsId;
	// friends name
	char			friendsName[MAX_PLAYER_NAME_LENGTH];
	// true, if player is a bot controlled by game.dll
	bool			fakeplayer;
	// true if player is the HLTV proxy
	bool			ishltv;
	// custom files CRC for this player
	unsigned int	customFiles[MAX_CUSTOM_FILES];
	// this counter increases each time the server downloaded a new file
	unsigned char	filesDownloaded;
};
class CEngineClient {
public:
	vMethod(void, getScreenSize, (int& w, int& h), (void*, int&, int&), 5, (this, w, h));
	vMethod(void, clientCMD, (const char* szCmdString), (void*, const char*), 7, (this, szCmdString));
	vMethod(bool, getPlayerInfo, (int entNum, PlayerInfo* pinfo), (void*, int, PlayerInfo*), 8, (this, entNum, pinfo));
	vMethod(int, getPlayerForUserID, (int userId), (void*, int), 9, (this, userId));
	vMethod(int, getLocalPlayer, (), (void*), 12, (this));
	vMethod(void, getViewAngles, (QAngle& angles), (void*, QAngle&), 18, (this, angles));
	vMethod(void, setViewAngles, (QAngle& angles), (void*, QAngle&), 19, (this, angles));
	vMethod(int, getMaxClients, (), (void*), 20, (this));
	vMethod(bool, isInGame, (), (void*), 26, (this));
	vMethod(bool, isConnected, (), (void*), 27, (this));
	vMethod(const char*, getLevelName, (), (void*), 53, (this));
	vMethod(INetChannelInfo*, getNetChannelInfo, (), (void*), 78, (this));
};