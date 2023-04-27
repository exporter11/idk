#pragma once

#include "vMethod.h"
#include "math.h"
#include "netchannelinfo.h"

#define MAX_PLAYER_NAME_LENGTH		128
#define SIGNED_GUID_LEN				32
#define MAX_CUSTOM_FILES			4

struct player_info
{
	// version for future compatibility
	unsigned __int64			version;
	// network xuid
	unsigned __int64			xuid;
	// scoreboard information
	char			name[MAX_PLAYER_NAME_LENGTH];
	// local server user ID, unique while server is running
	int				userID;
	// global unique player identifer
	char			guid[SIGNED_GUID_LEN + 1];
	// friends identification number
	unsigned int			friendsID;
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
	vMethod(bool, getPlayerInfo, (int ent_num, player_info* pinfo), (void*, int, player_info*), 8, (this, ent_num, pinfo));
	vMethod(int, getPlayerForUserID, (int userID), (void*, int), 9, (this, userID));
	vMethod(int, getLocalPlayer, (), (void*), 12, (this));
	vMethod(void, getViewAngles, (QAngle& angles), (void*, QAngle&), 18, (this, angles));
	vMethod(void, setViewAngles, (QAngle& angles), (void*, QAngle&), 19, (this, angles));
	vMethod(int, getMaxClients, (), (void*), 20, (this));
	vMethod(bool, isInGame, (), (void*), 26, (this));
	vMethod(bool, isConnected, (), (void*), 27, (this));
	vMethod(const char*, getLevelName, (), (void*), 53, (this));
	vMethod(INetChannelInfo*, getNetChannelInfo, (), (void*), 78, (this));
};