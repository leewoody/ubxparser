#include "RXM/UbxRxmAlmParser.hpp"

using namespace ublox ;
using namespace ublox::rxm ;

void AlmParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear();
    pToData->svid = bufferToULong( HEADER_SIZE , pbuffer ) ;
    pToData->almWeek = bufferToULong( HEADER_SIZE+4 , pbuffer ) ;
    if ( pToData->almWeek )
    {
        for ( int k = 0 ; k < 8 ; k++ )
        {
            int i0 = HEADER_SIZE + 8 ;
            pToData->dwrd[k] = bufferToULong( i0+k*4 , pbuffer ) ;
        }
    }
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
};

buffer_t AlmParser::generatePollRequest( U1 svid )
{
    buffer_t buf( 9 , char(0) );
    buf[0] = SYNC1 ;
    buf[1] = SYNC2 ;
    buf[2] = msg_cl ;
    buf[3] = msg_id ;
    buf[4] = 0 ;
    buf[5] = 1 ;
    buf[6] = svid ;
    computeCRC( buf[7] , buf[8] , &buf );
    return buf ;
} ;
