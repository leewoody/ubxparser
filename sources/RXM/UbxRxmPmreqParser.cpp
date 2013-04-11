#include "RXM/UbxRxmPmreqParser.hpp"

using namespace ublox ;
using namespace ublox::rxm ;

buffer_t PmreqParser::generatePmRequest( U4 duration , bool backup )
{
    buffer_t out( HEADER_SIZE + 8 + 2 ) ;
    X4 flags ;
    flags[1] = backup ;

    out[0] = SYNC1 ;
    out[1] = SYNC2 ;
    out[2] = msg_cl ;
    out[3] = msg_id ;
    out[4] = 0 ;
    out[5] = 8 ;

    unsigned char * pchar = reinterpret_cast<unsigned char*>( &duration );
    U4 flag( flags.to_ulong() );
    unsigned char * pchar2 = reinterpret_cast<unsigned char*>( &flag );
    for ( int k = 0 ; k < 4 ; k++ )
    {
        out[k+5] = pchar[k] ;
        out[k+9] = pchar2[k] ;
    }

    computeCRC( out[14] , out[15] , &out );
    return out ;
};
