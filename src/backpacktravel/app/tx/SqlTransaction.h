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

#ifndef RIPPLE_TX_SQLSTATEMENTTXS_H_INCLUDED
#define RIPPLE_TX_SQLSTATEMENTTXS_H_INCLUDED

#include <ripple/app/paths/RippleCalc.h>
#include <ripple/app/tx/impl/Transactor.h>
#include <ripple/basics/Log.h>
#include <ripple/protocol/TxFlags.h>
#include <backpacktravel/app/tx/BackpacktravelAlliancesTx.h>

namespace ripple {


class SqlTransaction
    : public BackpacktravelAlliancesTx
{
private:
    ripple::TER handleEachTx(ApplyContext& ctx);
    std::pair<TER, std::string> transactionImpl(ApplyContext& ctx_,ripple::TxStoreDBConn &txStoreDBConn, ripple::TxStore& txStore, beast::Journal journal, const STTx &tx);
public:
    SqlTransaction(ApplyContext& ctx)
        : BackpacktravelAlliancesTx(ctx)
    {
    }

    static
    BTAAmount
    calculateMaxSpend(STTx const& tx);

    static
    TER
    preflight (PreflightContext const& ctx);

    static
    TER
    preclaim(PreclaimContext const& ctx);

    TER doApply () override;

	std::pair<TER, std::string> dispose(TxStore& txStore, const STTx& tx);
};

} // ripple

#endif
