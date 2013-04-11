#ifndef __UBLOX_UBX_RXM_SVSI_PARSER__
#define __UBLOX_UBX_RXM_SVSI_PARSER__

#include "UbxDefinitions.hpp"
// #include "base/UbxParserBase.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace rxm
{

class SvsiParser : public ublox::TempParserBase<SvsiData>
{
public :
  SvsiParser() : ublox::TempParserBase<SvsiData>(RXM,SVSI,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

} ;

} ;
} ;

#endif
