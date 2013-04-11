#ifndef __UBLOX_UBX_ACK_PARSER__
#define __UBLOX_UBX_ACK_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace ack
{

class Parser : public ublox::TempParserBase<AckData>
{
public :
  Parser() : TempParserBase<AckData>(ACK,0) { } ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuffer );
};

};
};

#endif