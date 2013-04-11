#include "NAV/UbxNavSbasParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void SbasParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->iTow = bufferToULong( i0 , pbuffer );
    pToData->geo = bufferToUChar( i0+4 , pbuffer );
    pToData->mode = bufferToUChar( i0+5 , pbuffer );
    pToData->sys = bufferToChar( i0+6 , pbuffer );
    char flags = bufferToChar( i0+7 , pbuffer );
    for ( int k = 0 ; k < 4 ; k++ ) pToData->service[k] = extractBit(flags,k) ;
    pToData->cnt = bufferToUChar( i0+8 , pbuffer );

    for ( int k = 0 ; k < pToData->cnt ; k++ )
    {
        int i1 = HEADER_SIZE + 12 + 12 * k ;
        SbasBlock b ;
        b.svid = bufferToUChar( i1 , pbuffer );
        b.flags = bufferToUChar( i1+1 , pbuffer );
        b.udre = bufferToUChar( i1+2 , pbuffer );
        b.svSys = bufferToUChar( i1+3 , pbuffer );
        char v = bufferToChar( i1+4 , pbuffer );
        for ( int k = 0 ; k < 4 ; k++ ) b.svService[k] = extractBit(v,k);
        b.prc = bufferToShort( i1+6 , pbuffer );
        b.ic = bufferToShort( i1+10 , pbuffer );
        pToData->sv.push_back(b);
    }
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

// kate: indent-mode cstyle; space-indent on; indent-width 0;
