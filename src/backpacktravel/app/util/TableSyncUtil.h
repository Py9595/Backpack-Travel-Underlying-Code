//------------------------------------------------------------------------------
/*
This file is part of backpacktravelalliancesd: https://github.com/backpacktravelalliances/backpacktravelalliancesd
2016-2018 BACKPACK FOUNDATION W18235552G Corp.

backpacktravelalliancesd is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

backpacktravelalliancesd is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
//==============================================================================
#ifndef RIPPLE_RPC_TABLE_SYNC_UTIL_H_INCLUDED
#define RIPPLE_RPC_TABLE_SYNC_UTIL_H_INCLUDED

#include <ripple/ledger/ReadView.h>
#include <backpacktravel/protocol/STEntry.h>

namespace ripple {
	//table sync tool class
	class TableSyncUtil {
	public:
		static uint256 GetChainId(const ReadView * pView);
		static std::pair<bool, STEntry*> IsTableSLEChanged(const STArray& aTables, LedgerIndex iLastSeq, AccountID accountID, std::string sTableName, bool bStrictEqual);
	};
}

#endif