#include "CFG/UbxCfgRateParser.hpp"
#include "base/BufferConversion.hpp"

using namespace ublox ;

void cfg::RateParser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
{
    pToData->lock() ;
    pToData->clear();
    pToData->measRate = bufferToUShort( HEADER_SIZE , pbuf );
    pToData->navRate = bufferToUShort( HEADER_SIZE+2 , pbuf );
    pToData->timeRef = bufferToUShort( HEADER_SIZE+4 , pbuf ) ;
    pToData->unlock() ;

    if ( !this->asNoConnection() ) doneProcessing() ;
}

buffer_t cfg::RateParser::getConfigurationMsg( U2 measRate , U2 navRate , TIME_REF timeRef )
{
  boost::shared_ptr<RateData> config( new RateData ) ;
  config->measRate = measRate ;
  config->navRate = navRate ;
  config->timeRef = timeRef ;
  return RateParser::getConfigurationMsg(config) ;
};

buffer_t cfg::RateParser::getConfigurationMsg( boost::shared_ptr<RateData> config )
{
    buffer_t buf(HEADER_SIZE+6+CRC_SIZE,char(0)) ;
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = ublox::CFG ;
    buf[3] = ublox::cfg::RATE ;
    UShortToBuffer( 6 , 4 , &buf );
    UShortToBuffer( config->measRate , 6 , &buf );
    UShortToBuffer( config->navRate , 8 , &buf );
    UShortToBuffer( config->timeRef , 10 , &buf );
    computeCRC( buf[12] , buf[13] , &buf );
    return buf ;
};
