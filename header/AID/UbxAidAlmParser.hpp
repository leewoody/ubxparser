#ifndef __UBLOX_AID_ALM_PARSER__
#define __UBLOX_AID_ALM_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace aid
{

class AlmParser : public ublox::TempParserBase<AlmData>
{

public :
  AlmParser() : ublox::TempParserBase<AlmData>(AID,ALM,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER) pToData->display() ;
  };
  buffer_t generatePollRequest( U1 svid ) ;
} ;

} ;
} ;

#endif

