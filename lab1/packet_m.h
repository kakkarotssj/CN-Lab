//
// Generated file, do not edit! Created by nedtool 5.2 from packet.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __PACKET_M_H
#define __PACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Enum generated from <tt>packet.msg:20</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * enum msgType
 * {
 * 
 *     DATA = 1;
 *     ACK = 2;
 * }
 * </pre>
 */
enum msgType {
    DATA = 1,
    ACK = 2
};

/**
 * Class generated from <tt>packet.msg:27</tt> by nedtool.
 * <pre>
 * packet Packet
 * {
 *     int msgId;
 *     int src;
 *     int dest;
 * 
 *     int type \@enum(msgType);
 * }
 * </pre>
 */
class Packet : public ::omnetpp::cPacket
{
  protected:
    int msgId;
    int src;
    int dest;
    int type;

  private:
    void copy(const Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Packet&);

  public:
    Packet(const char *name=nullptr, short kind=0);
    Packet(const Packet& other);
    virtual ~Packet();
    Packet& operator=(const Packet& other);
    virtual Packet *dup() const override {return new Packet(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getMsgId() const;
    virtual void setMsgId(int msgId);
    virtual int getSrc() const;
    virtual void setSrc(int src);
    virtual int getDest() const;
    virtual void setDest(int dest);
    virtual int getType() const;
    virtual void setType(int type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Packet& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PACKET_M_H
