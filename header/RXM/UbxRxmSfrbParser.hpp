#ifndef __UBLOX_UBX_RXM_SFRB_PARSER__
#define __UBLOX_UBX_RXM_SFRB_PARSER__

#include "UbxDefinitions.hpp"
// #include "base/UbxParserBase.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{
namespace rxm
{

class SfrbParser : public ublox::TempParserBase<SfrbData>
{

  void assignSbasBuffer( SfrbBlock * block ) const ;

public :
  SfrbParser( ) : ublox::TempParserBase<SfrbData>(RXM,SFRB,true) { };

  void processFrame(  boost::shared_ptr<buffer_t> pbuf ) ;

  void debug()
  {
    if ( VERBOSE_PARSER )
      std::cout << "DWORDS added for SV " << (int)pToData->dwrds.back().svId << " on Channel " << (int)pToData->dwrds.back().chn << std::endl ;
  }
} ;

} ;
} ;

#endif
