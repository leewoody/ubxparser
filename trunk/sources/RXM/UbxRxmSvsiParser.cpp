#include "RXM/UbxRxmSvsiParser.hpp"

using namespace ublox ;
using namespace ublox::rxm ;

void SvsiParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;
    pToData->iTow = bufferToLong(i0,pbuffer);
    pToData->week = bufferToUShort(i0+4,pbuffer);
    pToData->numVis = bufferToUChar(i0+6,pbuffer);
    pToData->numSV = bufferToUChar(i0+7,pbuffer);
    for ( int i = 0 ; i < pToData->numSV ; i++ )
    {
        int j = HEADER_SIZE + 8 + 6 * i ;
        SvsiBlock b ;
        b.svid   = bufferToUChar(j,pbuffer);
        b.svFlag = bufferToUChar(j+1,pbuffer);
        b.azim   = bufferToShort(j+2,pbuffer) ;
        b.elev   = bufferToChar(j+4,pbuffer) ;
        b.age    = bufferToUChar(j+5,pbuffer) ;
        pToData->svInfos.push_back(b);
    }
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

