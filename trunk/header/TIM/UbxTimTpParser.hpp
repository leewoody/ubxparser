#ifndef __UBLOX_UBX_TIM_TP_PARSER__
#define __UBLOX_UBX_TIM_TP_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace tim
{

class TpParser : public ublox::TempParserBase<TpData>
{
public :
  TpParser() : ublox::TempParserBase<TpData>(TIM,TP,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

} ;

} ;
} ;

#endif
