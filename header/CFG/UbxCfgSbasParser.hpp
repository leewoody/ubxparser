#ifndef __UBLOX_CFG_SBAS_PARSER__
#define __UBLOX_CFG_SBAS_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace cfg
{

class SbasParser : public ublox::TempParserBase<SbasData>
{

public :

  SbasParser() : ublox::TempParserBase<SbasData>(ublox::CFG,ublox::cfg::SBAS,true) {} ;

  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

  static buffer_t getConfigurationMsg( boost::shared_ptr<SbasData> config ) ;

} ;

} ;
} ;

#endif
