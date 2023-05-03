#include "netvarmanager.h"
#include "interfaces.h"
int GetOffset(const RecvTable* pRecvTable, const char* szNetvar) {
	for (int i = 0; i < pRecvTable->m_nProps; i++) {
		const RecvProp recvProp = pRecvTable->m_pProps[i];
		if (!strcmp(recvProp.m_pVarName, szNetvar)) {
			return recvProp.m_Offset;
		}

		if (recvProp.m_pDataTable) {
			const int offset = GetOffset(recvProp.m_pDataTable, szNetvar);

			if (!offset)
				continue;

			return recvProp.m_Offset + offset;
		}
	}
	return 0;
}
int GetNetvarOffset(const char* szTable, const char* szNetvar) {
	const ClientClass* cn = interfaces::pBaseClientDll->getAllClasses();
	for (; cn; cn = cn->m_pNext) {
		const RecvTable* pRecvTable = cn->m_pRecvTable;
		if (!strcmp(pRecvTable->m_pNetTableName, szTable)) {
			return GetOffset(pRecvTable, szNetvar);
		}
	}
	return 0;
}
