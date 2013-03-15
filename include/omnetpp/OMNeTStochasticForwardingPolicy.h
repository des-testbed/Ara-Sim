/******************************************************************************
 Copyright 2012, The DES-SERT Team, Freie Universität Berlin (FUB).
 All rights reserved.

 hese sources were originally developed by Friedrich Große, Michael Frey
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

#ifndef OMNET_STOCHASTIC_FORWARDING_POLICY_H_
#define OMNET_STOCHASTIC_FORWARDING_POLICY_H_

#include <numeric>
#include <omnetpp.h>
#include <csimplemodule.h>


#include "RoutingTable.h"
#include "ForwardingPolicy.h"
#include "StochasticForwardingPolicy.h"

namespace ARA {
    namespace omnetpp {
           /**
            * The class provides a stochastic forwarding policy for class OMNeTARA. The
            * class overwrites the getRandomNumber() method of the base class. It uses a
            * pseudo-random number generator provided by OMNeT++.
            */
           class OMNeTStochasticForwardingPolicy : public cSimpleModule, public StochasticForwardingPolicy {
              protected:
                 /// The method returns a random number wich uses OMNeT++ pseudo random number generators
                 float getRandomNumber();

                 virtual void initialize();

                 virtual void handleMessage(cMessage *msg);
           };

    } /* namespace omnetpp */
} /* namespace ARA */

#endif
