#include "RXM/UbxRxmRawParser.hpp"

using namespace ublox ;
using namespace ublox::rxm ;

void RawParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;
    pToData->iTow = bufferToLong(i0,pbuffer);
    pToData->week = bufferToUShort(i0+4,pbuffer);
    pToData->numSV = bufferToUChar(i0+6,pbuffer);
    for ( int n = 0 ; n < pToData->numSV ; n++ )
    {
        RawMeasBlock meas ;
        int i1 = HEADER_SIZE + 8 + 24 * n ;
        meas.L1 = bufferToDouble( i1 , pbuffer ) ;
        meas.C1 = bufferToDouble( i1+8 , pbuffer ) ;
        meas.D1 = bufferToFloat( i1+16 , pbuffer ) ;
        meas.svId = bufferToUChar( i1+20 , pbuffer ) ;
        meas.QualIndic = pbuffer->at( i1+21 ) ;
        meas.snr = pbuffer->at( i1+22 ) ;
        meas.LLI = bufferToUChar( i1+23 , pbuffer ) ;
        pToData->meas.push_back(meas);
    }
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;
