#ifndef __UBLOX_UBX_NAV_POSECEF_PARSER__
#define __UBLOX_UBX_NAV_POSECEF_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class PosecefParser : public ublox::TempParserBase<PosecefData>
{
public :
  PosecefParser() : ublox::TempParserBase<PosecefData>(NAV,POSECEF,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
