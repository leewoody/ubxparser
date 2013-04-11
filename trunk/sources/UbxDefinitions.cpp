#include "UbxDefinitions.hpp"
#include "base/BufferConversion.hpp"
#include "ACK/UbxAckDefinitions.hpp"
#include "AID/UbxAidDefinitions.hpp"
#include "CFG/UbxCfgDefinitions.hpp"
#include "ESF/UbxEsfDefinitions.hpp"
#include "INF/UbxInfDefinitions.hpp"
#include "MON/UbxMonDefinitions.hpp"
#include "NAV/UbxNavDefinitions.hpp"
#include "RXM/UbxRxmDefinitions.hpp"
#include "TIM/UbxTimDefinitions.hpp"

//! Extract the message size from the header
ublox::U2 ublox::messageSize ( buffer_t * pbuf )
{
    return ( payloadSize(pbuf)  + ublox::HEADER_SIZE + ublox::CRC_SIZE ) ;
};

ublox::U2 ublox::payloadSize( buffer_t * pbuffer )
{
    return bufferToUShort ( 4 , pbuffer ) ;
}

//! Compute the CRC
bool ublox::checkCRC ( buffer_t * pbuffer )
{
    buffer_v a = 0 ;
    buffer_v b = 0 ;
    ublox::computeCRC(a,b,pbuffer);

    if ( ( a==pbuffer->at ( pbuffer->size()-2 ) ) && ( b==pbuffer->at ( pbuffer->size()-1 ) ) )
        return true;
    else
        return false ;
};

void ublox::computeCRC ( buffer_v & crc1 , buffer_v & crc2 , buffer_t * msg )
{
    crc1 = 0 ;
    crc2 = 0 ;
    for ( unsigned int i=2 ; i < ( msg->size()-2 ) ; i++ )
    {
        crc1 = crc1 + msg->at ( i );
        crc2 = crc2 + crc1  ;
    }
}

/*
 * shared_ptr version
 */
ublox::U2 ublox::messageSize ( boost::shared_ptr<ublox::buffer_t>  pbuf )
{
    return ( payloadSize(pbuf)  + ublox::HEADER_SIZE + ublox::CRC_SIZE ) ;
};

ublox::U2 ublox::payloadSize( boost::shared_ptr<ublox::buffer_t>  pbuffer )
{
    return bufferToUShort ( 4 , pbuffer ) ;
}

bool ublox::checkCRC ( boost::shared_ptr<ublox::buffer_t>  pbuffer )
{
    buffer_v a = 0 ;
    buffer_v b = 0 ;
    ublox::computeCRC(a,b,pbuffer);

//   std::cout << (int)a << " " << int(b) << " " << (int)pbuffer->at ( pbuffer->size()-2 ) << " " << (int)pbuffer->at ( pbuffer->size()-2 ) << std::endl ;

    if ( ( a==pbuffer->at ( pbuffer->size()-2 ) ) && ( b==pbuffer->at ( pbuffer->size()-1 ) ) )
        return true;
    else
        return false ;
};

void ublox::computeCRC ( buffer_v & crc1 , buffer_v & crc2 , boost::shared_ptr<ublox::buffer_t>  msg )
{
    crc1 = 0 ;
    crc2 = 0 ;
    for ( unsigned int i=2 ; i < ( msg->size()-2 ) ; i++ )
    {
        crc1 = crc1 + msg->at ( i );
        crc2 = crc2 + crc1  ;
    }
}



long ublox::subframeCorrection( long in )
{
    long subframe = in ;
    subframe <<= 6 ;
    subframe &= 0x3FFFFFC0 ;
    return subframe ;
};

std::string ublox::MsgIdAsString( const char & msg_cl , const char & msg_id )
{
    using namespace ublox ;
    std::string out("UBX ") ;
    if ( msg_cl == NAV )
    {
        out += "NAV-" ;
        using namespace ublox::nav ;
        if ( msg_id == AOPSTATUS ) out += "AOPSTATUS" ;
        else if ( msg_id == CLOCK ) out += "CLOCK" ;
        else if ( msg_id == DGPS ) out += "DGPS" ;
        else if ( msg_id == DOP ) out += "DOP" ;
        else if ( msg_id == EKFSTATUS ) out += "EKFSTATUS" ;
        else if ( msg_id == POSECEF ) out += "POSECEF" ;
        else if ( msg_id == POSLLH ) out += "POSLLH" ;
        else if ( msg_id == SBAS ) out += "SBAS" ;
        else if ( msg_id == SOL ) out += "SOL" ;
        else if ( msg_id == STATUS ) out += "STATUS" ;
        else if ( msg_id == SVINFO ) out += "SVINFO" ;
        else if ( msg_id == TIMEGPS ) out += "TIMEGPS" ;
        else if ( msg_id == TIMEUTC ) out += "TIMEUTC" ;
        else if ( msg_id == VELECEF ) out += "VELECEF" ;
        else if ( msg_id == VELNED ) out += "VELNED" ;
    }
    else if ( msg_cl == RXM )
    {
        out += "RXM-" ;
        using namespace ublox::rxm ;
        if ( msg_id == ALM ) out += "ALM" ;
        else if ( msg_id == EPH ) out += "EPH" ;
        else if ( msg_id == PMREQ ) out += "PMREQ" ;
        else if ( msg_id == RAW ) out += "RAW" ;
        else if ( msg_id == SFRB ) out += "SFRB" ;
        else if ( msg_id == SVSI ) out += "SVSI" ;
    }
    else if ( msg_cl == AID )
    {
        out += "AID-" ;
        using namespace ublox::aid ;
        if ( msg_id == ALM ) out += "ALM" ;
        else if ( msg_id == EPH ) out += "EPH" ;
        else if ( msg_id == ALPSRV ) out += "ALPSRV" ;
        else if ( msg_id == ALP ) out += "ALP" ;
        else if ( msg_id == AOP ) out += "AOP" ;
        else if ( msg_id == DATA ) out += "DATA" ;
        else if ( msg_id == HUI ) out += "HUI" ;
        else if ( msg_id == INI ) out += "INI" ;
        else if ( msg_id == REQ ) out += "REQ" ;
    }

    return out ;
} ;

// kate: indent-mode cstyle; space-indent on; indent-width 0;
