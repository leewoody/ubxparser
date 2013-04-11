#include "CFG/UbxCfgMsgParser.hpp"
#include "base/BufferConversion.hpp"

using namespace ublox ;

void cfg::MsgParser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
{
    pToData->lock() ;
    pToData->clear();
    pToData->msgClass = bufferToUChar( HEADER_SIZE , pbuf );
    pToData->msgID = bufferToUChar( HEADER_SIZE+1 , pbuf );

    if ( payloadSize(pbuf) == 3 )
    {
        pToData->rate = bufferToUChar( HEADER_SIZE+2 , pbuf );
    }
    else if ( payloadSize(pbuf) == 8 )
    {
        for ( unsigned int k = 0 ; k < 6 ; k++ )
            pToData->rates[k] = bufferToUChar( HEADER_SIZE+2+k , pbuf );
    }

    pToData->unlock() ;

    if ( !this->asNoConnection() ) doneProcessing() ;
}

buffer_t cfg::MsgParser::getConfigurationMsg( boost::shared_ptr<MsgData> config )
{
    buffer_t buf(16,char(0)) ;
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = ublox::CFG ;
    buf[3] = ublox::cfg::MSG ;
    UShortToBuffer(8,4,&buf);
    UCharToBuffer( config->msgClass , 6 , &buf ) ;
    UCharToBuffer( config->msgID , 7 , &buf ) ;
    for ( unsigned int k = 0 ; k < 6 ; k++ )
      UCharToBuffer( config->rates[k] , k+8 , &buf );
    computeCRC( buf[14] , buf[15] , &buf );
    return buf ;
};

buffer_t cfg::MsgParser::getConfigurationMsg( U1 msgClass , U1 msgId , U1 rate , cfg::RX_PORT port )
{
    buffer_t buf(16,char(0)) ;
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = ublox::CFG ;
    buf[3] = ublox::cfg::MSG ;
    UShortToBuffer(8,4,&buf);
    UCharToBuffer( msgClass , 6 , &buf ) ;
    UCharToBuffer( msgId , 7 , &buf ) ;
    if ( port == ALL )
        for (unsigned int k = 8 ; k < 13 ; k++ )
	  UCharToBuffer( rate , k , &buf );
    else
       UCharToBuffer( rate , port+8 , &buf );
    computeCRC( buf[14] , buf[15] , &buf );
    return buf ;
};
