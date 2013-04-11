#ifndef __UBLOX_UBX_INF_DEFINITIONS__
#define __UBLOX_UBX_INF_DEFINITIONS__

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 INF = 0x04 ;

namespace inf
{

const I1 DEBUG = 0x04 ;
const I1 ERROR = 0x00 ;
const I1 NOTICE = 0x02 ;
const I1 TEST 	= 0x03 ;
const I1 WARNING = 0x01  ;

class DebugData ;
class ErrorData ;
class NoticeData ;
class TestData ;
class WarningData ;

} ;

} ;

#endif
