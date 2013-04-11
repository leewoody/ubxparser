#ifndef __UBLOX_UBX_NAV_SBAS_PARSER__
#define __UBLOX_UBX_NAV_SBAS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class SbasParser : public ublox::TempParserBase<SbasData>
{
public :
  SbasParser() : ublox::TempParserBase<SbasData>(NAV,SBAS,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
