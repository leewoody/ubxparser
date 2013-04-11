#ifndef __UBLOX_UBX_NAV_AOPSTATUS_PARSER__
#define __UBLOX_UBX_NAV_AOPSTATUS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class AopstatusParser : public ublox::TempParserBase<AopstatusData>
{
public :
  AopstatusParser() : ublox::TempParserBase<AopstatusData>( NAV , AOPSTATUS , true ) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
