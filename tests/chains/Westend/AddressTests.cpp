// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HexCoding.h"
#include "Westend/Address.h"
#include "PublicKey.h"
#include "PrivateKey.h"
#include <gtest/gtest.h>
#include <vector>

namespace TW::Westend::tests {

TEST(WestendAddress, Validation) {
    // Substrate ed25519
    ASSERT_TRUE(Address::isValid("5FqqU2rytGPhcwQosKRtW1E3ha6BJKAjHgtcodh71dSyXhoZ"));

    // Polkadot ed25519
    ASSERT_FALSE(Address::isValid("15AeCjMpcSt3Fwa47jJBd7JzQ395Kr2cuyF5Zp4UBf1g9ony"));
    // Polkadot sr25519
    ASSERT_FALSE(Address::isValid("15AeCjMpcSt3Fwa47jJBd7JzQ395Kr2cuyF5Zp4UBf1g9ony"));
    // Bitcoin
    ASSERT_FALSE(Address::isValid("1ES14c7qLb5CYhLMUekctxLgc1FV2Ti9DA"));
    // Kusama ed25519
    ASSERT_FALSE(Address::isValid("FHKAe66mnbk8ke8zVWE9hFVFrJN1mprFPVmD5rrevotkcDZ"));
    // Kusama secp256k1
    ASSERT_FALSE(Address::isValid("FxQFyTorsjVsjjMyjdgq8w5vGx8LiA1qhWbRYcFijxKKchx"));
    // Kusama sr25519
    ASSERT_FALSE(Address::isValid("EJ5UJ12GShfh7EWrcNZFLiYU79oogdtXFUuDDZzk7Wb2vCe"));
}

TEST(WestendAddress, FromPrivateKey) {
    auto privateKey = PrivateKey(parse_hex("0xf327156fc1a84e6d3fafe72724e8326fc70e0479bdd42570f919139c27da4b1a"));
    auto address = Address(privateKey.getPublicKey(TWPublicKeyTypeED25519));
    ASSERT_EQ(address.string(), "5ECidQbr7Pj6hnEHXEvPcqiSUamzkcK4wicj3zGXNtrhwbCo");
}

TEST(WestendAddress, FromPublicKey) {
    auto publicKey = PublicKey(parse_hex("0x5e9506dac44a2c86bff4b8e2db1d739e1bc5b3b061f1acd73a7189fe5d2372de"), TWPublicKeyTypeED25519);
    auto address = Address(publicKey);
    ASSERT_EQ(address.string(), "5ECidQbr7Pj6hnEHXEvPcqiSUamzkcK4wicj3zGXNtrhwbCo");
}

TEST(WestendAddress, FromString) {
    auto address = Address("5ECidQbr7Pj6hnEHXEvPcqiSUamzkcK4wicj3zGXNtrhwbCo");
    ASSERT_EQ(address.string(), "5ECidQbr7Pj6hnEHXEvPcqiSUamzkcK4wicj3zGXNtrhwbCo");
}

} // namespace TW::Westend::tests