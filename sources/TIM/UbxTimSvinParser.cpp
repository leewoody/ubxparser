#include "TIM/UbxTimSvinParser.hpp"

using namespace ublox ;
using namespace ublox::tim ;

void SvinParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->dur = bufferToULong(i0,pbuffer);
    pToData->meanX = bufferToLong(i0+4,pbuffer);
    pToData->meanY = bufferToLong(i0+8,pbuffer);
    pToData->meanZ = bufferToLong(i0+12,pbuffer);
    pToData->meanV = bufferToULong(i0+16,pbuffer);
    pToData->obs = bufferToULong(i0+20,pbuffer);
    pToData->valid = bufferToUChar(i0+24,pbuffer);
    pToData->active = bufferToUChar(i0+25,pbuffer) ;
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

