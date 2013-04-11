#ifndef __UBLOX_UBX_NAV_EKFSTATUS_PARSER__
#define __UBLOX_UBX_NAV_EKFSTATUS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class EkfstatusParser : public ublox::TempParserBase<EkfstatusData>
{
public :
  EkfstatusParser() : ublox::TempParserBase<EkfstatusData>( NAV , EKFSTATUS , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
