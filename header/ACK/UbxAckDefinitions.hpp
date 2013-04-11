#ifndef __UBLOX_UBX_ACK_DEFINITIONS__
#define __UBLOX_UBX_ACK_DEFINITIONS__

#include <iostream>
#include <vector>
#include <bitset>

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const char ACK = 0x05 ;

namespace ack
{
const char ACK = 0x01 ; //! Message acknoledged
const char NAK = 0x00 ; //! Message not acknoledged

class AckData : public ublox::BaseData
{
public :
  AckData() : ublox::BaseData(ACK,ack::ACK)
  {
    this->clear();
  }
  bool acknoledged ;
  I1 clsID ;
  I1 msgID ;
  void clear()
  {
    acknoledged = false ;
    clsID = 0 ;
    msgID = 0 ;
  };
};

};

};

#endif