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

#include "app_layer.h"

Define_Module(App_layer);

void App_layer::initialize()
{
    // TODO - Generated method body
    fromData = gate("fromData");
    toData = gate("toData");
    appId = par("appId");
    messageCount = 0;

    if (appId == 1)
    {
        cMessage *self_message = new cMessage();
        scheduleAt(0, self_message);
    }
}

void App_layer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if (messageCount < 10)
    {
        if (appId == 1)
        {
            if (msg->isSelfMessage())
            {
                A_PDU* firstMessage = new A_PDU();
                firstMessage->setId(messageCount);
                firstMessage->setType("DATA");
                send(firstMessage, toData);

                messageCount += 1;
            }
            else
            {
                A_PDU* oldMessage = new A_PDU();
                oldMessage = check_and_cast<A_PDU*>(msg);
                oldMessageId = oldMessage->getId();

                A_PDU* newMessage = new A_PDU();
                newMessage->setType("DATA");
                newMessage->setId(oldMessageId+1);
                send(newMessage, toData);

                messageCount += 1;
            }
        }
        else
        {
            A_PDU* oldMessage = new A_PDU();
            oldMessage = check_and_cast<A_PDU*>(msg);
            oldMessageId = oldMessage->getId();

            A_PDU* ackMessage = new A_PDU();
            ackMessage->setType("ACK");
            ackMessage->setId(oldMessageId);
            send(ackMessage, toData);
        }
    }
}
