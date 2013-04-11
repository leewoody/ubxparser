#include "CFG/UbxCfgNav5Parser.hpp"
#include "base/BufferConversion.hpp"

using namespace ublox ;

void cfg::Nav5Parser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
{
    pToData->lock() ;
    pToData->clear();

    pToData->mask = bufferToX2(HEADER_SIZE,pbuf) ;

    unsigned char d = bufferToUChar(HEADER_SIZE+2,pbuf) ;
    if ( d == 0 ) pToData->dynModel = PORTABLE ;
    else if ( d == 2 ) pToData->dynModel = STATIONARY ;
    else if ( d == 3 ) pToData->dynModel = PEDESTRIAN ;
    else if ( d == 4 ) pToData->dynModel = AUTOMOTIVE ;
    else if ( d == 5 ) pToData->dynModel = SEA ;
    else if ( d == 6 ) pToData->dynModel = AIRBORNE_1G ;
    else if ( d == 7 ) pToData->dynModel = AIRBORNE_2G ;
    else if ( d == 8 ) pToData->dynModel = AIRBORNE_4G ;

    U1 f = bufferToUChar(HEADER_SIZE+3,pbuf) ;
    if ( f == 1 ) pToData->fixMode = TWOD_ONLY ;
    else if ( f == 2 ) pToData->fixMode = THREED_ONLY ;
    else if ( f == 3 ) pToData->fixMode = AUTO ;

    pToData->fixedAlt = bufferToLong(HEADER_SIZE+4,pbuf) ;
    pToData->fixedAltVar = bufferToULong(HEADER_SIZE+8,pbuf) ;
    pToData->minElev = bufferToChar(HEADER_SIZE+12,pbuf) ;
    pToData->drLimit = bufferToUChar(HEADER_SIZE+13,pbuf) ;
    pToData->pDop = bufferToUShort(HEADER_SIZE+14,pbuf);
    pToData->tDop = bufferToUShort(HEADER_SIZE+16,pbuf) ;
    pToData->pAcc = bufferToUShort(HEADER_SIZE+18,pbuf) ;
    pToData->tAcc = bufferToUShort(HEADER_SIZE+20,pbuf) ;
    pToData->staticHoldThres = bufferToUChar(HEADER_SIZE+22,pbuf) ;
    pToData->dgpsTimeOut = bufferToUChar(HEADER_SIZE+23,pbuf);

    pToData->unlock() ;

    if ( !this->asNoConnection() ) doneProcessing() ;
}

buffer_t cfg::Nav5Parser::getConfigurationMsg( boost::shared_ptr<Nav5Data> config )
{
    buffer_t buf( HEADER_SIZE+36+CRC_SIZE , char(0) ) ;
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = ublox::CFG ;
    buf[3] = ublox::cfg::NAV5 ;
    UShortToBuffer( 36 , 4 , &buf );
    UShortToBuffer( config->mask.to_ulong() , HEADER_SIZE , &buf );
    buf[HEADER_SIZE+2] = config->dynModel ;
    buf[HEADER_SIZE+3] = config->fixMode ;
    ULongToBuffer(config->fixedAlt,HEADER_SIZE+4,&buf) ;
    ULongToBuffer(config->fixedAltVar,HEADER_SIZE+8,&buf) ;
    buf[HEADER_SIZE+12] = config->minElev ;
    buf[HEADER_SIZE+13] = config->drLimit ;
    ULongToBuffer(config->pDop,HEADER_SIZE+14,&buf) ;
    ULongToBuffer(config->tDop,HEADER_SIZE+16,&buf) ;
    ULongToBuffer(config->pAcc,HEADER_SIZE+18,&buf) ;
    ULongToBuffer(config->tAcc,HEADER_SIZE+20,&buf) ;
    UCharToBuffer( config->staticHoldThres , HEADER_SIZE+22 , &buf );
    UCharToBuffer( config->dgpsTimeOut , HEADER_SIZE+23 , &buf );
    computeCRC( buf[42] , buf[43] , &buf );
    return buf ;
};
