#include "TIM/UbxTimTm2Parser.hpp"

using namespace ublox ;
using namespace ublox::tim ;

void Tm2Parser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->ch = bufferToUChar(i0,pbuffer) ;
    pToData->flags = bufferToX1(i0+1,pbuffer);
    pToData->count = bufferToUShort(i0+2,pbuffer);
    pToData->wnR = bufferToUShort(i0+4,pbuffer);
    pToData->wnF = bufferToUShort(i0+6,pbuffer);
    pToData->towMsR = bufferToULong(i0+8,pbuffer) ;
    pToData->towSubMsR = bufferToULong(i0+12,pbuffer);
    pToData->towMsF = bufferToULong(i0+16,pbuffer);
    pToData->towSubMsF = bufferToULong(i0+20,pbuffer) ;
    pToData->accEst = bufferToULong(i0+24,pbuffer) ;
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

