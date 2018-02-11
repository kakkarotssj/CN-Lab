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

#include "node.h"

Define_Module(Node);


void Node::initialize()
{
    // TODO - Generated method body

    input_gate = gate("in");
    output_gate = gate("out");
    node_address = par("id");
    message_count = 10;

    if (node_address == 1)
    {
        cMessage* self_message = new cMessage();
        scheduleAt(0, self_message);
    }
}


void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if (message_count > 0)
    {
        if (msg->isSelfMessage())
            {
                Packet* first_message = new Packet();
                first_message->setMsgId(1);
                first_message->setSrc(1);
                first_message->setDest(2);
                first_message->setType(1);
                message_count -= 1;
                send(first_message, output_gate);
            }

            else
            {
                Packet* received_message = new Packet();
                received_message = check_and_cast<Packet*>(msg);

                if (received_message->getDest() == 2)
                {
                    Packet* ack_message = new Packet();
                    dataMsgId = received_message->getMsgId();
                    ack_message->setMsgId(dataMsgId);
                    ack_message->setType(2);
                    ack_message->setSrc(2);
                    ack_message->setDest(1);
                    send(ack_message, output_gate);
                }
                else
                {
                    Packet *data_message = new Packet();
                    ackMsgId = received_message->getMsgId();
                    data_message->setMsgId(ackMsgId+1);
                    data_message->setSrc(1);
                    data_message->setDest(2);
                    data_message->setType(1);
                    send(data_message, output_gate);
                    message_count -= 1;
                }
            }
    }
}


// commented part below is for (a) part of Behavioural Design

//void Node::initialize()
//{
//    // TODO - Generated method body
//
//    input_gate = gate("in");
//    output_gate = gate("out");
//    node_address = par("id");
//
//    if (node_address == 1)
//    {
//        cMessage* self_message = new cMessage();
//        scheduleAt(0, self_message);
//    }
//}
//
//void Node::handleMessage(cMessage *msg)
//{
//    // TODO - Generated method body
//
//    if (msg->isSelfMessage())
//    {
//        Packet* first_message = new Packet();
//        first_message->setMsgId(1);
//        first_message->setSrc(1);
//        first_message->setDest(2);
//        first_message->setType(1);
//        send(first_message, output_gate);
//    }
//    else
//    {
//        Packet* received_message = new Packet();
//        received_message = check_and_cast<Packet*>(msg);
//        if (received_message->getType() == 1)
//        {
//            Packet *ack_message = new Packet();
//            ack_message->setMsgId(2);
//            ack_message->setSrc(2);
//            ack_message->setDest(1);
//            ack_message->setType(2);
//            send(ack_message, output_gate);
//        }
//    }
//}
