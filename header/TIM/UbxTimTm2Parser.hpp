#ifndef __UBLOX_UBX_TIM_TM2_PARSER__
#define __UBLOX_UBX_TIM_TM2_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace tim
{

class Tm2Parser : public ublox::TempParserBase<Tm2Data>
{
public :
  Tm2Parser() : ublox::TempParserBase<Tm2Data>(TIM,TM2,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

} ;

} ;
} ;

#endif
