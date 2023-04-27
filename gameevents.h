#pragma once
#define NULL 0
#define uint64 unsigned __int64
// Class for visiting every key of data on an event
class IGameEventVisitor2
{
public:
	// return true to keep iterating, false to abort iteration
	virtual bool VisitLocal(const char* name, const void* value) { return true; }
	virtual bool VisitString(const char* name, const char* value) { return true; }
	virtual bool VisitFloat(const char* name, float value) { return true; }
	virtual bool VisitInt(const char* name, int value) { return true; }
	virtual bool VisitUint64(const char* name, unsigned __int64 value) { return true; }
	virtual bool VisitWString(const char* name, const wchar_t* value) { return true; }
	virtual bool VisitBool(const char* name, bool value) { return true; }
};

class IGameEvent
{
public:
	virtual ~IGameEvent() {};
	virtual const char* GetName() const = 0;	// get event name


	virtual bool  IsReliable() const = 0; // if event handled reliable
	virtual bool  IsLocal() const = 0; // if event is never networked
	virtual bool  IsEmpty(const char* keyName = NULL) const = 0; // check if data field exists

	// Data access
	virtual bool  GetBool(const char* keyName = NULL, bool defaultValue = false) const = 0;
	virtual int   GetInt(const char* keyName = NULL, int defaultValue = 0) const = 0;
	virtual uint64 GetUint64(const char* keyName = NULL, uint64 defaultValue = 0) const = 0;
	virtual float GetFloat(const char* keyName = NULL, float defaultValue = 0.0f) const = 0;
	virtual const char* GetString(const char* keyName = NULL, const char* defaultValue = "") const = 0;
	virtual const wchar_t* GetWString(const char* keyName = NULL, const wchar_t* defaultValue = L"") const = 0;
	virtual const void* GetPtr(const char* keyName = NULL) const = 0;	// LOCAL only

	virtual void SetBool(const char* keyName, bool value) = 0;
	virtual void SetInt(const char* keyName, int value) = 0;
	virtual void SetUint64(const char* keyName, uint64 value) = 0;
	virtual void SetFloat(const char* keyName, float value) = 0;
	virtual void SetString(const char* keyName, const char* value) = 0;
	virtual void SetWString(const char* keyName, const wchar_t* value) = 0;
	virtual void SetPtr(const char* keyName, const void* value) = 0;	// LOCAL only

	// returns true if iteration aborted normally, false if it was aborted by the visitor callback
	virtual bool ForEventData(IGameEventVisitor2* event) const = 0;
};