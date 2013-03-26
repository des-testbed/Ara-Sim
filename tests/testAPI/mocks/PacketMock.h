/*
 * $FU-Copyright$
 */

#ifndef PACKETMOCK_H_
#define PACKETMOCK_H_

#include "Packet.h"
#include "PacketType.h"
#include "Address.h"
#include <memory>

namespace ARA {

class PacketMock: public Packet {
public:
    PacketMock(const char* sourceName = "Source", const char* destinationName = "Destination", unsigned int sequenceNumber = 1, unsigned int hopCount = 0, char packetType = PacketType::DATA);
    PacketMock(const char* sourceName, const char* destinationName, const char* senderName, unsigned int sequenceNumber = 1, unsigned int hopCount = 0, char packetType = PacketType::DATA, const char* payload= "Hello World");

    bool operator==(PacketMock& other) {
        return this->equals(&other);
    }

    void setSender(std::shared_ptr<Address> newSenderAddress);
};

} /* namespace ARA */
#endif /* PACKETMOCK_H_ */
