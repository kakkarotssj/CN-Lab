//
// Generated file, do not edit! Created by nedtool 5.2 from DL_PDU.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __DL_PDU_M_H
#define __DL_PDU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>DL_PDU.msg:20</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet DL_PDU
 * {
 *     int id;
 *     string type;
 * }
 * </pre>
 */
class DL_PDU : public ::omnetpp::cPacket
{
  protected:
    int id;
    ::omnetpp::opp_string type;

  private:
    void copy(const DL_PDU& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DL_PDU&);

  public:
    DL_PDU(const char *name=nullptr, short kind=0);
    DL_PDU(const DL_PDU& other);
    virtual ~DL_PDU();
    DL_PDU& operator=(const DL_PDU& other);
    virtual DL_PDU *dup() const override {return new DL_PDU(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);
    virtual const char * getType() const;
    virtual void setType(const char * type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DL_PDU& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DL_PDU& obj) {obj.parsimUnpack(b);}


#endif // ifndef __DL_PDU_M_H

