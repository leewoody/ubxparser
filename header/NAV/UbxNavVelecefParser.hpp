#ifndef __UBLOX_UBX_NAV_VELECEF_PARSER__
#define __UBLOX_UBX_NAV_VELECEF_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class VelecefParser : public ublox::TempParserBase<VelecefData>
{
public :
  VelecefParser( ) : ublox::TempParserBase<VelecefData>(NAV,VELECEF,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
