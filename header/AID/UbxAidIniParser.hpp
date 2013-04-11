#ifndef __UBLOX_AID_INI_PARSER__
#define __UBLOX_AID_INI_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace aid
{

class IniParser : public ublox::TempParserBase<IniData>
{

public :
  IniParser() : ublox::TempParserBase<IniData>(AID,INI,true) {} ;
  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;
  void debug()
  {
    if ( VERBOSE_PARSER) pToData->display() ;
  };
} ;

} ;
} ;

#endif

