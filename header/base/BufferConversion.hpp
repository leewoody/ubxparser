#ifndef __BUFFER_CONVERSION__
#define __BUFFER_CONVERSION__

#include <sstream>
#include <vector>
#include <list>
#include <bitset>
#include <iostream>
// #include <QtEndian>
// #include <boost/detail/endian.hpp>

#include "base/UbxDatatype.hpp"

/*!
 * \brief Converts to unsigned char
 * \var startByte
 * \var pbuffer
 *
 * Converts the buffer to unsigned char starting from startByte.
 */
unsigned char bufferToUChar( int startByte , ublox::buffer_t * pbuffer ) ;
char bufferToChar( int startByte , ublox::buffer_t * pbuffer );
unsigned short bufferToUShort( int startByte , ublox::buffer_t *pbuffer ) ;
short bufferToShort( int startByte , ublox::buffer_t * pbuffer );
unsigned long bufferToULong( int startByte , ublox::buffer_t *pbuffer ) ;
long bufferToLong( int startByte , ublox::buffer_t * pbuffer );
float bufferToFloat( int startByte , ublox::buffer_t * pbuffer ) ;
double bufferToDouble( int startByte , ublox::buffer_t * pbuffer ) ;
bool extractBit(char byte, int pos) ;
std::bitset<8> bufferToX1( int startByte , ublox::buffer_t * pbuffer );
std::bitset<16> bufferToX2( int startByte , ublox::buffer_t * pbuffer );
std::bitset<32> bufferToX4( int startByte , ublox::buffer_t * pbuffer );

unsigned char bufferToUChar( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer ) ;
char bufferToChar( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );
unsigned short bufferToUShort( int startByte , boost::shared_ptr<ublox::buffer_t>pbuffer ) ;
short bufferToShort( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );
unsigned long bufferToULong( int startByte , boost::shared_ptr<ublox::buffer_t>pbuffer ) ;
long bufferToLong( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );
float bufferToFloat( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer ) ;
double bufferToDouble( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer ) ;
bool extractBit(char byte, int pos) ;
std::bitset<8> bufferToX1( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );
std::bitset<16> bufferToX2( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );
std::bitset<32> bufferToX4( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer );

// unsigned char extractUChar( char byte , int startPos , int length );
// char extractChar( char byte , int startPos , int length );
unsigned char  extractSFID ( const long int * DWRD ) ;
unsigned short extractTOW ( const long int * DWRD ) ;
unsigned short extractSVID ( const long int * DWRD ) ;

// template<class T> std::string encodeVar( const T& v )
// {
//    T tmp = qToLittleEndian(v) ;
//    return std::string( reinterpret_cast<char*>( &tmp ), sizeof( tmp ) );
//

void UCharToBuffer( unsigned char val , unsigned int startByte , ublox::buffer_t * p_buffer ) ;
void UShortToBuffer( unsigned short val , unsigned int startByte , ublox::buffer_t * pbuffer ) ;
void ShortToBuffer( short val , uint startByte , ublox::buffer_t * pbuffer ) ;
void ULongToBuffer( uint val , uint startByte , ublox::buffer_t * pbuffer ) ;
void LongToBuffer( int val , uint startByte , ublox::buffer_t * pbuffer ) ;
void FloatToBuffer( float val , uint startByte , ublox::buffer_t * pbuffer ) ;
void DoubleToBuffer( double val , uint startByte , ublox::buffer_t * pbuffer ) ;
void X1ToBuffer( std::bitset<8> val , uint startByte , ublox::buffer_t * pbuffer ) ;
void X2ToBuffer( std::bitset<16> val , uint startByte , ublox::buffer_t * pbuffer ) ;
void X4ToBuffer( std::bitset<32> val , uint startByte , ublox::buffer_t * pbuffer ) ;


#endif
