#ifndef __UBLOX_CFG_RATE_PARSER__
#define __UBLOX_CFG_RATE_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace cfg
{

class RateParser : public ublox::TempParserBase<RateData>
{

public :

  RateParser() : ublox::TempParserBase<RateData>(ublox::CFG,ublox::cfg::RATE,true) {} ;

  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

  static buffer_t getConfigurationMsg( boost::shared_ptr<RateData> config ) ;
  static buffer_t getConfigurationMsg( U2 measRate , U2 navRate , TIME_REF timeRef ) ;

} ;

} ;
} ;

#endif
