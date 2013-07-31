/*
 * $FU-Copyright$
 */

#include "testbed/NetworkInterface.h"
#include "TestbedAddress.h"
#include "PacketDispatcher.h"

TESTBED_NAMESPACE_BEGIN

AddressPtr NetworkInterface::broadcastAddress = AddressPtr(new TestbedAddress(DESSERT_BROADCAST_ADDRESS));
extern NetworkInterfaceMap networkInterfaces;

NetworkInterface::NetworkInterface(dessert_meshif_t* dessertPointer, AbstractNetworkClient* client, int ackTimeoutInMicroSeconds)
                        : ReliableNetworkInterface(client, ackTimeoutInMicroSeconds, AddressPtr(new TestbedAddress(dessertPointer->hwaddr)), broadcastAddress) {
    this->dessertPointer = dessertPointer;
    registerInterface();
}

NetworkInterface::~NetworkInterface() {
    networkInterfaces.erase(dessertPointer);
}

bool NetworkInterface::isRegistered() {
    return extractNetworkInterface(dessertPointer) == this;
}

void NetworkInterface::receive(Packet* packet) {
    deliverToARAClient(packet);
}

void NetworkInterface::deliverToARAClient(Packet* packet) {
    client->receivePacket(packet, this);
}

bool NetworkInterface::equals(ARA::NetworkInterface* otherInterface) {
    ARA::testbed::NetworkInterface* other = (ARA::testbed::NetworkInterface*)otherInterface;
    return this->dessertPointer->hwaddr == other->dessertPointer->hwaddr;
}

dessert_meshif_t* NetworkInterface::getDessertPointer()  const{
    return this->dessertPointer;
}

void NetworkInterface::doSend(const Packet* packet, std::shared_ptr<Address> recipient){
    packetToMeshInterfaceDispatcher(packet, this, recipient);
}

void NetworkInterface::registerInterface() {
    networkInterfaces[this->getDessertPointer()] = this;
}

TESTBED_NAMESPACE_END
