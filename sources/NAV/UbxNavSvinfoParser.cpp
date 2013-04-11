#include "NAV/UbxNavSvinfoParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void SvinfoParser::processFrame( boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;
    pToData->iTow = bufferToULong( i0 , pbuffer );
    pToData->numCh = bufferToUChar( i0+4 , pbuffer );
    pToData->globalFlags = bufferToChar( i0+5 , pbuffer );
    for ( int k = 0 ; k < pToData->numCh ; k++ )
    {
        int i1 = HEADER_SIZE + 8 + 12 * k ;
        SvinfoBlock b ;
        b.chId = bufferToUChar( i1 , pbuffer ) ;
        b.svId = bufferToUChar( i1+1 , pbuffer );
        b.flags = bufferToX1( i1+2 , pbuffer ) ;
        b.quality = bufferToChar( i1+3 , pbuffer );
        b.cn0 = bufferToUChar( i1+4 , pbuffer ) ;
        b.elev = bufferToChar( i1+5 , pbuffer ) ;
        b.azim = bufferToShort( i1+6 , pbuffer ) ;
        b.prRes = bufferToLong( i1+8 , pbuffer );
        pToData->chData.push_back(b);
    }
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;
