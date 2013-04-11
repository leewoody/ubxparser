#ifndef __UBLOX_RXM_ALM_PARSER__
#define __UBLOX_RXM_ALM_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace rxm
{

class AlmParser : public ublox::TempParserBase<AlmData>
{

public :
  AlmParser() : ublox::TempParserBase<AlmData>(RXM,ALM,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  buffer_t generatePollRequest( U1 svid ) ;
} ;

} ;
} ;

#endif
