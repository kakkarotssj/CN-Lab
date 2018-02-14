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

#include "data_layer.h"

Define_Module(Data_layer);

void Data_layer::initialize()
{
    // TODO - Generated method body
    fromApp = gate("fromApp");
    fromPhysical = gate("fromPhysical");
    toApp = gate("toApp");
    toPhysical = gate("toPhysical");
    dataId = par("dataId");
}

void Data_layer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (msg->getArrivalGate() == fromApp)
    {
        A_PDU* appLayerMessage = new A_PDU();
        appLayerMessage = check_and_cast<A_PDU*>(msg);
        appLayerMessageId = appLayerMessage->getId();
        appLayerMessageType = appLayerMessage->getType();

        DL_PDU* dataLayerMessage = new DL_PDU();
        dataLayerMessage->encapsulate(appLayerMessage);
        dataLayerMessage->setId(appLayerMessageId % 2);
        dataLayerMessage->setType(appLayerMessageType);

        send(dataLayerMessage, toPhysical);
    }
    else
    {
        DL_PDU* physicalLayerMessage = new DL_PDU();
        physicalLayerMessage = check_and_cast<DL_PDU*>(msg);
        physicalLayerMessageId = physicalLayerMessage->getId();
        physicalLayerMessageType = physicalLayerMessage->getType();

        A_PDU* dataLayerMessage = new A_PDU();
        dataLayerMessage = check_and_cast<A_PDU*>(physicalLayerMessage->decapsulate());
        dataLayerMessage->setId(physicalLayerMessageId);
        dataLayerMessage->setType(physicalLayerMessageType);

        send(dataLayerMessage, toApp);
    }
}
