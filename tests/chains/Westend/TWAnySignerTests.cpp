// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "proto/Polkadot.pb.h"
#include "uint256.h"
#include "TestUtilities.h"
#include <TrustWalletCore/TWAnySigner.h>

#include <gtest/gtest.h>

namespace TW::Polkadot::tests {

TEST(TWAnySignerWestend, Sign) {
    auto key = parse_hex("0xf327156fc1a84e6d3fafe72724e8326fc70e0479bdd42570f919139c27da4b1a");
    auto genesisHash = parse_hex("0xe143f23803ac50e8f6f8e62695d1ce9e4e1d68aa36c1cd2cfd15340213f3423e");

    Proto::SigningInput input;
    input.set_block_hash(genesisHash.data(), genesisHash.size());
    input.set_genesis_hash(genesisHash.data(), genesisHash.size());
    input.set_nonce(1);
    input.set_spec_version(2019);
    input.set_private_key(key.data(), key.size());
    input.set_network(Proto::Network::WESTEND);
    input.set_transaction_version(2);

    auto balanceCall = input.mutable_balance_call();
    auto& transfer = *balanceCall->mutable_transfer();
    auto value = store(uint256_t(10000000000));
    transfer.set_to_address("5ECidQbr7Pj6hnEHXEvPcqiSUamzkcK4wicj3zGXNtrhwbCo");
    transfer.set_value(value.data(), value.size());

    Proto::SigningOutput output;
    ANY_SIGN(input, TWCoinTypeWestend);

    ASSERT_EQ(hex(output.encoded()), "3502845e9506dac44a2c86bff4b8e2db1d739e1bc5b3b061f1acd73a7189fe5d2372de008413c0e09829c226d3b8174ac1831ee707e8bbb63eb7ec08dd6b19c7f259e5bc5743b4da5fee861a493d424b61ea208a323be7fbbfdb6cc7dc2ef67844281a0b00040004005e9506dac44a2c86bff4b8e2db1d739e1bc5b3b061f1acd73a7189fe5d2372de0700e40b5402");
}

} // namespace TW::Polkadot::tests
