#include "TIM/UbxTimTpParser.hpp"

using namespace ublox ;
using namespace ublox::tim ;

void TpParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->towMS = bufferToULong(i0,pbuffer) ;
    pToData->towSubMS = bufferToULong(i0+4,pbuffer);
    pToData->qErr = bufferToLong(i0+8,pbuffer);
    pToData->week = bufferToUShort(i0+12,pbuffer);
    pToData->flags = bufferToX1(i0+14,pbuffer);

    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

