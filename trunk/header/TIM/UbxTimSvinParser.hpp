#ifndef __UBLOX_UBX_TIM_SVIN_PARSER__
#define __UBLOX_UBX_TIM_SVIN_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace tim
{

class SvinParser : public ublox::TempParserBase<SvinData>
{
public :
  SvinParser() : ublox::TempParserBase<SvinData>(TIM,SVIN,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

} ;

} ;
} ;

#endif
