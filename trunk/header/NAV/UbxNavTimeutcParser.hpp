#ifndef __UBLOX_UBX_NAV_TIMEUTC_PARSER__
#define __UBLOX_UBX_NAV_TIMEUTC_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class TimeutcParser : public ublox::TempParserBase<TimeutcData>
{
public :
  TimeutcParser() : ublox::TempParserBase<TimeutcData>( NAV , TIMEUTC , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
