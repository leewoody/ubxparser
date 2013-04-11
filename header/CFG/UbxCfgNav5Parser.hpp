#ifndef __UBLOX_CFG_NAV5_PARSER__
#define __UBLOX_CFG_NAV5_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace cfg
{

class Nav5Parser : public ublox::TempParserBase<Nav5Data>
{

public :

  Nav5Parser() : ublox::TempParserBase<Nav5Data>(ublox::CFG,ublox::cfg::NAV5,true) {} ;

  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

  static buffer_t getConfigurationMsg( boost::shared_ptr<Nav5Data> config ) ;

} ;

} ;
} ;

#endif
