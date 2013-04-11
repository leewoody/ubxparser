#include "CFG/UbxCfgSbasParser.hpp"
#include "base/BufferConversion.hpp"

using namespace ublox ;

void cfg::SbasParser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
{
    pToData->lock() ;
    pToData->clear();
    pToData->mode = bufferToX1( HEADER_SIZE , pbuf );
    pToData->usage = bufferToX1( HEADER_SIZE+1 , pbuf );
    pToData->maxSbas = bufferToChar( HEADER_SIZE+2 , pbuf );
    pToData->scanmode2 = bufferToX1( HEADER_SIZE+3 , pbuf );
    pToData->scanmode1 = bufferToX4( HEADER_SIZE+4 , pbuf );
    pToData->unlock() ;

    if ( !this->asNoConnection() ) doneProcessing() ;
}

buffer_t cfg::SbasParser::getConfigurationMsg( boost::shared_ptr<SbasData> config )
{
    buffer_t buf( HEADER_SIZE + 8 + CRC_SIZE ,char(0)) ;
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = ublox::CFG ;
    buf[3] = ublox::cfg::SBAS ;
    UShortToBuffer( 8 , 4 , &buf );
    X1ToBuffer( config->mode , HEADER_SIZE , &buf );
    X1ToBuffer( config->usage , HEADER_SIZE+1 , &buf );
    UCharToBuffer( config->maxSbas , HEADER_SIZE+2 , &buf ) ;
    X1ToBuffer( config->scanmode2 , HEADER_SIZE+3 , &buf );
    X4ToBuffer( config->scanmode1 , HEADER_SIZE+4 , &buf );

    computeCRC( buf[14] , buf[15] , &buf );
    return buf ;
};
