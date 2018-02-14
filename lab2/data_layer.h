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

#ifndef __LAB2_DATA_LAYER_H_
#define __LAB2_DATA_LAYER_H_

#include <omnetpp.h>
#include "DL_PDU_m.h"
#include "A_PDU_m.h"
#include "P_PDU_m.h"
#include <string.h>

using namespace std;
using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Data_layer : public cSimpleModule
{
  protected:
    cGate* fromApp;
    cGate* fromPhysical;
    cGate* toApp;
    cGate* toPhysical;
    int dataId;
    const char* appLayerMessageType;
    int appLayerMessageId;
    const char* physicalLayerMessageType;
    int physicalLayerMessageId;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
