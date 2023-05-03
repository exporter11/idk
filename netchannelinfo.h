#pragma once
#define FLOW_OUTGOING	0		
#define FLOW_INCOMING	1
#define MAX_FLOWS		2		// in & out

class INetChannelInfo
{
public:

	enum {
		GENERIC = 0,	// must be first and is default group
		LOCALPLAYER,	// bytes for local player entity update
		OTHERPLAYERS,	// bytes for other players update
		ENTITIES,		// all other entity bytes
		SOUNDS,			// game sounds
		EVENTS,			// event messages
		TEMPENTS,		// temp entities
		USERMESSAGES,	// user messages
		ENTMESSAGES,	// entity messages
		VOICE,			// voice data
		STRINGTABLE,	// a string table update
		MOVE,			// client move commands
		STRINGCMD,		// string command
		SIGNON,			// various sign-on data
		PAINTMAP,			// paint map data
		ENCRYPTED,		// encrypted data
		TOTAL,			// must be last and is not a real group
	};

	enum ENetworkEventTypeT
	{
		K_ENETWORK_EVENT_TYPE_GENERIC = 0,		// Generic network event
		K_ENETWORK_EVENT_TYPE_TIMEDOUT
	};

	virtual const char* getName(void) const = 0;	// get channel name
	virtual const char* getAddress(void) const = 0; // get channel IP address as string
	virtual float		getTime(void) const = 0;	// current net time
	virtual float		getTimeConnected(void) const = 0;	// get connection time in seconds
	virtual int			getBufferSize(void) const = 0;	// net channel packet history size
	virtual int			getDataRate(void) const = 0; // send data rate in byte/sec

	virtual bool		isLoopback(void) const = 0;	// true if loopback channel
	virtual bool		isTimingOut(void) const = 0;	// true if timing out
	virtual bool		isPlayback(void) const = 0;	// true if demo playback

	virtual float		getLatency(int flow) const = 0;	 // current latency (RTT), more accurate but jittering
	virtual float		getAvgLatency(int flow) const = 0; // average packet latency in seconds
	virtual float		getAvgLoss(int flow) const = 0;	 // avg packet loss[0..1]
	virtual float		getAvgChoke(int flow) const = 0;	 // avg packet choke[0..1]
	virtual float		getAvgData(int flow) const = 0;	 // data flow in bytes/sec
	virtual float		getAvgPackets(int flow) const = 0; // avg packets/sec
	virtual int			getTotalData(int flow) const = 0;	 // total flow in/out in bytes
	virtual int			getTotalPackets(int flow) const = 0;
	virtual int			getSequenceNr(int flow) const = 0;	// last send seq number
	virtual bool		isValidPacket(int flow, int frame_number) const = 0; // true if packet was not lost/dropped/chocked/flushed
	virtual float		getPacketTime(int flow, int frame_number) const = 0; // time when packet was send
	virtual int			getPacketBytes(int flow, int frame_number, int group) const = 0; // group size of this packet
	virtual bool		getStreamProgress(int flow, int* received, int* total) const = 0;  // TCP progress if transmitting
	virtual float		getTimeSinceLastReceived(void) const = 0;	// get time since last recieved packet in seconds
	virtual	float		getCommandInterpolationAmount(int flow, int frame_number) const = 0;
	virtual void		getPacketResponseLatency(int flow, int frame_number, int* pnLatencyMsecs, int* pnChoke) const = 0;
	virtual void		getRemoteFramerate(float* pflFrameTime, float* pflFrameTimeStdDeviation, float* pflFrameStartTimeStdDeviation) const = 0;

	virtual float		getTimeoutSeconds() const = 0;
};
