#pragma once
class RecvTable;
class RecvProp;
class ClientClass; 
class ClientClass
{
public:
	void* m_pCreateFn;
	void* m_pCreateEventFn;	// Only called for event objects.
	char* m_pNetworkName;
	RecvTable* m_pRecvTable;
	ClientClass* m_pNext;
	int						m_ClassID;	// Managed by the engine.
	const char* m_pMapClassname;
};

class RecvProp
{
public:

	char* m_pVarName;
	void*			m_RecvType;
	int						m_Flags;
	int						m_StringBufferSize;


	bool					m_bInsideArray;	
	const void* m_pExtraData;
	RecvProp* m_pArrayProp;
	void* m_ArrayLengthProxy;
	void* m_ProxyFn;
	void* m_DataTableProxyFn;	
	RecvTable* m_pDataTable;		
	int						m_Offset;
	int						m_ElementStride;
	int						m_nElements;
	const char* m_pParentArrayPropName;
};


class RecvTable
{
public:
	RecvProp* m_pProps;
	int				m_nProps;
	void* m_pDecoder;
	char* m_pNetTableName;
	bool			m_bInitialized;
	bool			m_bInMainList;
};