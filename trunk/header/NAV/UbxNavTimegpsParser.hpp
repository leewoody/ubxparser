#ifndef __UBLOX_UBX_NAV_TIMEGPS_PARSER__
#define __UBLOX_UBX_NAV_TIMEGPS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class TimegpsParser : public ublox::TempParserBase<TimegpsData>
{
public :
  TimegpsParser( ) : ublox::TempParserBase<TimegpsData>(NAV,TIMEGPS,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
