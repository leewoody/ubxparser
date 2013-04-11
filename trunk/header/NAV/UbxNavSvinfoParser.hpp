#ifndef __UBLOX_UBX_NAV_SVINFO_PARSER__
#define __UBLOX_UBX_NAV_SVINFO_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class SvinfoParser : public ublox::TempParserBase<SvinfoData>
{
public :
  SvinfoParser() : ublox::TempParserBase<SvinfoData>(NAV,SVINFO,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;
} ;

} ;
} ;

#endif
