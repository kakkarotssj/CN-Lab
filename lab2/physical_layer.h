//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __LAB2_PHYSICAL_LAYER_H_
#define __LAB2_PHYSICAL_LAYER_H_

#include <omnetpp.h>
#include "P_PDU_m.h"
#include "DL_PDU_m.h"
#include <string.h>

using namespace omnetpp;
using namespace std;

/**
 * TODO - Generated class
 */
class Physical_layer : public cSimpleModule
{
  protected:
    cGate* fromNode;
    cGate* fromData;
    cGate* toNode;
    cGate* toData;
    int physicalId;
    const char* dataLayerMessageType;
    int dataLayerMessageId;
    const char* nodeMessageType;
    int nodeMessageId;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
