#ifndef __UBLOX_UBX_NAV_POSLLH_PARSER__
#define __UBLOX_UBX_NAV_POSLLH_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class PosllhParser : public ublox::TempParserBase<PosllhData>
{
public :
  PosllhParser() : ublox::TempParserBase<PosllhData>(NAV,POSLLH,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
