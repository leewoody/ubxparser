#ifndef __UBLOX_UBX_NAV_CLOCK_PARSER__
#define __UBLOX_UBX_NAV_CLOCK_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class ClockParser : public ublox::TempParserBase<ClockData>
{
public :
  ClockParser() : ublox::TempParserBase<ClockData>( NAV , CLOCK , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
