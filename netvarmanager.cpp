#include "netvarmanager.h"
#include "interfaces.h"
int getOffset(RecvTable* recvtable, const char* szNetvar) {
	for (int i = 0; i < recvtable->m_nProps; i++) {
		RecvProp recvprop = recvtable->m_pProps[i];
		if (!strcmp(recvprop.m_pVarName, szNetvar)) {
			return recvprop.m_Offset;
		}

		if (recvprop.m_pDataTable) {
			int offset = getOffset(recvprop.m_pDataTable, szNetvar);
			if (offset)
				return recvprop.m_Offset + offset;
		}
	}
	return 0;
}
int getNetvarOffset(const char* szTable, const char* szNetvar) {
	for (ClientClass* cn = interfaces::p_baseclient->getAllClasses(); cn; cn = cn->m_pNext) {
		RecvTable* recvtable = cn->m_pRecvTable;
		if (!strcmp(recvtable->m_pNetTableName, szTable)) {
			return getOffset(recvtable, szNetvar);
		}
	}
	return 0;
}
