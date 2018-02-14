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

#include "physical_layer.h"

Define_Module(Physical_layer);

void Physical_layer::initialize()
{
    // TODO - Generated method body
    fromNode = gate("fromNode");
    fromData = gate("fromData");
    toNode = gate("toNode");
    toData = gate("toData");
    physicalId = par("physicalId");
}

void Physical_layer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->getArrivalGate() == fromData)
    {
        DL_PDU* dataLayerMessage = new DL_PDU();
        dataLayerMessage = check_and_cast<DL_PDU*>(msg);
        dataLayerMessageId = dataLayerMessage->getId();
        dataLayerMessageType = dataLayerMessage->getType();

        P_PDU* physicalLayerMessage = new P_PDU();
        physicalLayerMessage->encapsulate(dataLayerMessage);
        physicalLayerMessage->setId(dataLayerMessageId);
        physicalLayerMessage->setType(dataLayerMessageType);

        send(physicalLayerMessage, toNode);
    }
    else
    {
        P_PDU* nodeMessage = new P_PDU();
        nodeMessage = check_and_cast<P_PDU*>(msg);
        nodeMessageId = nodeMessage->getId();
        nodeMessageType = nodeMessage->getType();

        DL_PDU* physicalLayerMessage = new DL_PDU();
        physicalLayerMessage = check_and_cast<DL_PDU*>(nodeMessage->decapsulate());

        send(physicalLayerMessage, toData);
    }
}
