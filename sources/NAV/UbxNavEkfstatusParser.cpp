#include "NAV/UbxNavEkfstatusParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void EkfstatusParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->pulses = bufferToLong(i0,pbuffer) ;
    pToData->period = bufferToLong(i0+4,pbuffer) ;
    pToData->gyroMean = bufferToULong(i0+8,pbuffer) ;
    pToData->temperature = bufferToShort(i0+12,pbuffer) ;
    pToData->direction = bufferToChar(i0+14,pbuffer) ;
    pToData->calibStatus = bufferToX1(i0+15,pbuffer) ;
    pToData->pulseScale = bufferToLong(i0+16,pbuffer);
    pToData->gyroBias = bufferToLong(i0+20,pbuffer);
    pToData->gyroScale = bufferToLong(i0+24,pbuffer) ;
    pToData->accPulseScale= bufferToShort(i0+28,pbuffer);
    pToData->accGyroBias = bufferToShort(i0+30,pbuffer) ;
    pToData->accGyroScale= bufferToShort(i0+32,pbuffer) ;
    pToData->measUsed = bufferToX1(i0+34,pbuffer) ;

    debug() ;
    pToData->unlock() ;
    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;


