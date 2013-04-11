#ifndef __UBLOX_CFG_MSG_PARSER__
#define __UBLOX_CFG_MSG_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace cfg
{

class MsgParser : public ublox::TempParserBase<MsgData>
{

public :

  MsgParser() : ublox::TempParserBase<MsgData>(ublox::CFG,ublox::cfg::MSG,true) {} ;

  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

  static buffer_t getConfigurationMsg( boost::shared_ptr<MsgData> config ) ;
  static buffer_t getConfigurationMsg( U1 msgClass , U1 msgId , U1 rate , cfg::RX_PORT port ) ;

} ;

} ;
} ;

#endif
