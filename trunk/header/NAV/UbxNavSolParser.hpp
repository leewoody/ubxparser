#ifndef __UBLOX_UBX_NAV_SOL_PARSER__
#define __UBLOX_UBX_NAV_SOL_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace nav
{

class SolParser : public ublox::TempParserBase<SolData>
{
public :
  SolParser() : ublox::TempParserBase<SolData>(NAV,SOL,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER ) pToData->display();
  } ;

} ;

} ;
} ;

#endif
