// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "TestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(TWWestendCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeWestend));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("0x0dcc0e4bc921be72a65b953c1964136223e834d246991752f530b034d8ae3e9f"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeWestend, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("5F62BRKoBEZs1bGRb68yCo5gL25gzrMFDmJ4QHxtxeXJsuhg"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeWestend, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeWestend));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeWestend));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeWestend), 12);
    ASSERT_EQ(TWBlockchainWestend, TWCoinTypeBlockchain(TWCoinTypeWestend));
    ASSERT_EQ(0x0, TWCoinTypeP2shPrefix(TWCoinTypeWestend));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeWestend));
    assertStringsEqual(symbol, "WDOT");
    assertStringsEqual(txUrl, "https://westend.subscan.io/extrinsic/0x0dcc0e4bc921be72a65b953c1964136223e834d246991752f530b034d8ae3e9f");
    assertStringsEqual(accUrl, "https://westend.subscan.io/account/5F62BRKoBEZs1bGRb68yCo5gL25gzrMFDmJ4QHxtxeXJsuhg");
    assertStringsEqual(id, "westend");
    assertStringsEqual(name, "Westend");
}
