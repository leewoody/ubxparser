#ifndef __UBLOX_UBX_MON_DEFINITIONS__
#define __UBLOX_UBX_MON_DEFINITIONS__

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 MON = 0x0A ;

namespace mon
{
  const I1 HW2 = 0x0B ;
  const I1 HW = 0x09 ;
  const I1 IO = 0x02 ;
  const I1 MSGPP = 0x06 ;
  const I1 RXBUF = 0x07 ;
  const I1 RXR = 0x21 ;
  const I1 TXBUF = 0x08 ;
  const I1 VER = 0x04 ;
  
  class Hw2Data ;
  class HwData ;
  class IoData ;
  class MsgppData ;
  class RxbufData ;
  class RxrData ;
  class TxbufData ;
  class VerData ;
  
} ;
} ;

#endif
