#ifndef __UBLOX_UBX_NAV_DOP_PARSER__
#define __UBLOX_UBX_NAV_DOP_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class DopParser : public ublox::TempParserBase<DopData>
{
public :
  DopParser() : ublox::TempParserBase<DopData>( NAV , DOP , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
