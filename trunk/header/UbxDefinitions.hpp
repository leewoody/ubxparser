/*!
 * \file UbxDefinitions.hpp
 * \author Clément Fouque
 * \version 1.0
 * \date 26/05/2011
 */

#ifndef __UBLOX_UBX_DEFINITION__
#define __UBLOX_UBX_DEFINITION__

#include <vector>
#include <map>
#include <bitset>

// #include <QtEndian>
// #include <QVariant>

#include "base/UbxDatatype.hpp"

namespace ublox
{

//! Sets the verbosoity of the parser
const bool VERBOSE_PARSER = false ;

//! Size of UBX header message
const unsigned short HEADER_SIZE = 6 ;

//! Size of CRC Check
const unsigned short CRC_SIZE = 2 ;

//! Number of Receiver channel
const unsigned short NB_CHANNEL = 50 ;

//! First synchronisation char for UBX Frame
const char SYNC1 = 0xB5 ;

//! Second synchronisation char for UBX Frame
const char SYNC2 = 0x62 ;


/*!
 * \brief compute message id
 * Compute a uniique msg id from msg_cl and msg_id
 */
inline MSG_ID getMsgUniqueId ( const char & msg_cl , const char & msg_id )
{
    return msg_cl * 256 + msg_id ;
};

/*!
 * \brief get the payload size
 * This function extracts the payload size from the buffer.
 */
U2 payloadSize( buffer_t * pbuffer );
U2 payloadSize( boost::shared_ptr<buffer_t> pbuffer );

/*!
 * \brief computes the message size from buffer
 * Payload size + header + CRC
 * */
U2 messageSize ( buffer_t * pbuffer ) ;
U2 messageSize ( boost::shared_ptr<buffer_t> pbuffer ) ;

/*!
 * \brief Check if the message is CRC valid.
 */
bool checkCRC ( buffer_t * pbuffer ) ;
bool checkCRC ( boost::shared_ptr<buffer_t> pbuffer ) ;

/*!
 * \brief Compute the values for CRC.
 */
void computeCRC ( buffer_v & crc1 , buffer_v & crc2 , buffer_t * pbuffer ) ;
void computeCRC ( buffer_v & crc1 , buffer_v & crc2 , boost::shared_ptr<buffer_t> pbuffer ) ;

/*!
 * \brief Corrects the subframe.s
 */
long subframeCorrection( long subframe ) ;

/*!
 * \brief get the Message name
 */
std::string MsgIdAsString( const char & msg_cl , const char & msg_id ) ;

}; // End of namespace ublox

// Ubx inclusion:
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

#endif
// kate: indent-mode cstyle; space-indent on; indent-width 0;
