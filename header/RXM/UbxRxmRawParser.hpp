#ifndef __UBLOX_UBX_RXM_RAW_PARSER__
#define __UBLOX_UBX_RXM_RAW_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace rxm
{

class RawParser : public ublox::TempParserBase<RawData>
{

public :
  RawParser() : ublox::TempParserBase<RawData>(RXM,RAW,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER) pToData->display() ;
  };
  
} ;

} ;
} ;

#endif
