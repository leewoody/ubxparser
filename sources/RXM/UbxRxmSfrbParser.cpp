#include "RXM/UbxRxmSfrbParser.hpp"

using namespace ublox ;
using namespace ublox::rxm ;

void SfrbParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    SfrbBlock bdata ;
    bdata.chn = bufferToUChar( HEADER_SIZE , pbuffer) ;
    bdata.svId = bufferToUChar( HEADER_SIZE+1 , pbuffer ) ;
    for ( int k = 0 ; k < 10 ; k++ )
        bdata.dwrd[k] =  bufferToLong( HEADER_SIZE+2+4*k , pbuffer ) ;

    if ((bdata.svId==120) || (bdata.svId==122) || (bdata.svId==124)
            || (bdata.svId==126) || (bdata.svId==129) ||(bdata.svId==131)
            || (bdata.svId==134) || (bdata.svId==137))
    {
        this->assignSbasBuffer( &bdata );
    }


    if ( pToData->dwrds.size() > MAX_NUMBER_SFRB_BLOCKS ) pToData->dwrds.pop_front() ;
    pToData->dwrds.push_back( bdata );
    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;

void SfrbParser::assignSbasBuffer( SfrbBlock* block ) const
{
    block->sbas_buffer.clear() ;
    block->sbas_buffer.reserve(32);

    unsigned char * pTmp ;
    signed long tSl ;

    for (int i=0; i<7; i++)
    {
        pTmp = (unsigned char *) (& block->dwrd[i]);
        for (int j=3; j>=0; j--)
            block->sbas_buffer.push_back(pTmp[j]);
    }

    /* WORD 8 after reading from little indian

     31 ... 27 26 25 24 23 22 ... 01 00
    ____________________________________
    |XXXXXXXXXXXX|     |   PArity      |
    ----------------^-------------------
    				|
    				Last two bits
    */
    tSl = block->dwrd[7];
    tSl = tSl << 6;
    pTmp = (unsigned char *) (& tSl);
    for (int j=3; j>=0; j--)
        block->sbas_buffer.push_back(pTmp[j]);
} ;
