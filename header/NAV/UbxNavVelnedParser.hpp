#ifndef __UBLOX_UBX_NAV_VELNED_PARSER__
#define __UBLOX_UBX_NAV_VELNED_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class VelnedParser : public ublox::TempParserBase<VelnedData>
{
public :
  VelnedParser() : ublox::TempParserBase<VelnedData>(NAV,VELNED,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
