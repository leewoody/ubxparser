#ifndef __UBLOX_UBX_TIM_VRFY_PARSER__
#define __UBLOX_UBX_TIM_VRFY_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace tim
{

class VrfyParser : public ublox::TempParserBase<VrfyData>
{
public :
  VrfyParser() : ublox::TempParserBase<VrfyData>(TIM,VRFY,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

} ;

} ;
} ;

#endif
