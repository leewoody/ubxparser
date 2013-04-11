#ifndef __UBLOX_UBX_NAV_STATUS_PARSER__
#define __UBLOX_UBX_NAV_STATUS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class StatusParser : public ublox::TempParserBase<StatusData>
{
public :
  StatusParser() : ublox::TempParserBase<StatusData>( NAV , STATUS , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
