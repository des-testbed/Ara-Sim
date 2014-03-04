/*
 * $FU-Copyright$
 */

#ifndef _NETWORK_INTERFACE_H_
#define _NETWORK_INTERFACE_H_

#include "Testbed.h"
#include "AbstractARAClient.h"
#include "ReliableNetworkInterface.h"

TESTBED_NAMESPACE_BEGIN

class NetworkInterface : public ReliableNetworkInterface {
    public:
        NetworkInterface(dessert_meshif_t* dessertPointer, AbstractARAClient* client, PacketFactory* packetFactory, int ackTimeoutInMicroSeconds);
        ~NetworkInterface();
        bool isRegistered();
        bool equals(ARA::NetworkInterface* otherInterface);
        dessert_meshif_t* getDessertPointer()  const;

    protected:
        void doSend(const Packet* packet, std::shared_ptr<Address> recipient);
        static AddressPtr localAddress;
        static AddressPtr broadcastAddress;
        dessert_meshif_t* dessertPointer;

    private:
        void registerInterface();
};

TESTBED_NAMESPACE_END

#endif // _NETWORK_INTERFACE_H_
