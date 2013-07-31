/*
 * $FU-Copyright$
 */

#ifndef OMNET_FORWARDING_POLICY_H_
#define OMNET_FORWARDING_POLICY_H_

#include "OMNeTARAMacros.h"
#include "ForwardingPolicy.h"
#include "RoutingTable.h"

OMNETARA_NAMESPACE_BEGIN

/**
* This interface does mainly exist because OMNeT++ does only support the standard constructor
* for its SimpleModules. This class implements that and adds a setRoutingTable method which
* MUST BE CALLED before this object is used.
*
* It also gives a standard implementation of handleMessage which just throws an exception
* if the simulation tries to use it (should never be called).
*/
class OMNeTForwardingPolicy : public virtual ForwardingPolicy, public cSimpleModule {
    public:
        virtual ~OMNeTForwardingPolicy() {};

        /**
         * This must be called after the constructor, because stupid OMNeT++ does only allow standard constructors...
         */
        virtual void setRoutingTable(RoutingTable* routingTable) = 0;

    protected:

        virtual void handleMessage(cMessage* message) {
            throw cRuntimeError("handleMessage() should never be called on an OMNeTForwardingPolicy!");
        }
};

OMNETARA_NAMESPACE_END

#endif
