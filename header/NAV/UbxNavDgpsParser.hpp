#ifndef __UBLOX_UBX_NAV_DGPS_PARSER__
#define __UBLOX_UBX_NAV_DGPS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class DgpsParser : public ublox::TempParserBase<DgpsData>
{
public :
  DgpsParser() : ublox::TempParserBase<DgpsData>( NAV , DGPS , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
