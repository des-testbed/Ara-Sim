/*
 * Packet.cpp
 *
 *  Created on: Dec 2, 2012
 *      Author: Friedrich Große
 */

#include "Packet.h"
#include "PacketType.h"

namespace ARA {

Packet::Packet(Address* source, Address* destination, char type, unsigned int seqNr, const char* payload, unsigned int payloadSize, unsigned int hopCount) {
    this->source = source;
    this->destination = destination;
    this->type = type;
    this->seqNr = seqNr;
    this->payload = payload;
    this->payloadSize = payloadSize;
    this->hopCount = hopCount;
}

Packet::~Packet() {
    delete this->source;
    delete this->destination;
}

Address* Packet::getSource() {
    return source;
}

Address* Packet::getDestination() {
    return destination;
}

char Packet::getType() {
    return type;
}

unsigned int Packet::getSequenceNumber() {
    return seqNr;
}

unsigned int Packet::getHopCount() {
    return hopCount;
}

const char* Packet::getPayload() {
    return payload;
}

unsigned int Packet::getPayloadLength() {
    return payloadSize;
}

Packet* Packet::createFANT(unsigned int sequenceNumber) {
    Packet* fant = new Packet(source->clone(), destination->clone(), PacketType::FANT, sequenceNumber);
    return fant;
}

} /* namespace ARA */