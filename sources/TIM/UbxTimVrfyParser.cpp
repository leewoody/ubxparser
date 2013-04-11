#include "TIM/UbxTimVrfyParser.hpp"

using namespace ublox ;
using namespace ublox::tim ;

void VrfyParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->itow = bufferToLong(i0,pbuffer) ;
    pToData->frac = bufferToLong(i0+4,pbuffer);
    pToData->deltaMs = bufferToLong(i0+8,pbuffer) ;
    pToData->deltaNs = bufferToLong(i0+12,pbuffer);
    pToData->wno = bufferToUShort(i0+16,pbuffer) ;
    pToData->flags = bufferToX1(i0+18,pbuffer);

    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

