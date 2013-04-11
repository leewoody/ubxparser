#ifndef __UBLOX_UBX_ESF_DEFINITIONS__
#define __UBLOX_UBX_ESF_DEFINITIONS__

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 ESF = 0x10 ;

namespace esf
{
  const I1 MEAS = 0x02 ;
  const I1 STATUS = 0x10 ;
  
  class MeasData ;
  class StatusData ;
} ;
} ;

#endif
