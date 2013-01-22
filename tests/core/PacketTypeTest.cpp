/******************************************************************************
 Copyright 2012, The DES-SERT Team, Freie Universität Berlin (FUB).
 All rights reserved.

 These sources were originally developed by Friedrich Große
 at Freie Universität Berlin (http://www.fu-berlin.de/),
 Computer Systems and Telematics / Distributed, Embedded Systems (DES) group
 (http://cst.mi.fu-berlin.de/, http://www.des-testbed.net/)
 ------------------------------------------------------------------------------
 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation, either version 3 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with
 this program. If not, see http://www.gnu.org/licenses/ .
 ------------------------------------------------------------------------------
 For further information and questions please use the web site
 http://www.des-testbed.net/
 *******************************************************************************/

#include "CppUTest/TestHarness.h"
#include "PacketType.h"

using namespace ARA;

TEST_GROUP(PacketTypeTest) {};

TEST(PacketTypeTest, testIsAntPacket) {
    CHECK(PacketType::isAntPacket(PacketType::FANT) == true);
    CHECK(PacketType::isAntPacket(PacketType::BANT) == true);
    CHECK(PacketType::isAntPacket(PacketType::PANT) == true);
    CHECK(PacketType::isAntPacket(PacketType::DATA) == false);
    CHECK(PacketType::isAntPacket(PacketType::DUPLICATE_ERROR) == false);
}

TEST(PacketTypeTest, testIsDataPacket) {
    CHECK(PacketType::isDataPacket(PacketType::FANT) == false);
    CHECK(PacketType::isDataPacket(PacketType::BANT) == false);
    CHECK(PacketType::isDataPacket(PacketType::PANT) == false);
    CHECK(PacketType::isDataPacket(PacketType::DATA) == true);
    CHECK(PacketType::isDataPacket(PacketType::DUPLICATE_ERROR) == false);
}

TEST(PacketTypeTest, testGetAsString) {
    CHECK_EQUAL("FANT", PacketType::getAsString(PacketType::FANT));
    CHECK_EQUAL("BANT", PacketType::getAsString(PacketType::BANT));
    CHECK_EQUAL("PANT", PacketType::getAsString(PacketType::PANT));
    CHECK_EQUAL("DATA", PacketType::getAsString(PacketType::DATA));
    CHECK_EQUAL("DUPLICATE_ERROR", PacketType::getAsString(PacketType::DUPLICATE_ERROR));
    CHECK_EQUAL("UNKOWN", PacketType::getAsString(5));
}
