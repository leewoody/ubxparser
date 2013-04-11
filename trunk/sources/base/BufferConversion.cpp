#include "base/BufferConversion.hpp"
#include <endian.h>

//! Returns the buffer value as an unsigned char
unsigned char bufferToUChar( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer )
{
  return static_cast<unsigned char>( pbuffer->at( startByte ) );
} ;

unsigned char bufferToUChar( int startByte , ublox::buffer_t * pbuffer )
{
  return static_cast<unsigned char>( pbuffer->at( startByte ) );
};

//! Returns the buffer value as a char
char bufferToChar( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer )
{
  return pbuffer->at( startByte );
} ;

char bufferToChar( int startByte , ublox::buffer_t * pbuffer )
{
  return pbuffer->at( startByte );
} ;

//! Return the buffer value as as Unsigned short integer (int8)
unsigned short bufferToUShort( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer )
{
  char tab2[2];
  unsigned short *pushort;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 2 ; i++ ) tab2[2-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 2 ; i++ ) tab2[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<2; i++) tab2[i]=pbuffer->at(startByte+i);
//   *(tab2) = qFromLittleEndian(*(tab2));
  pushort = reinterpret_cast<unsigned short *>(tab2);
  return *pushort;
};

unsigned short bufferToUShort( int startByte , ublox::buffer_t *pbuffer )
{
  char tab2[2];
  unsigned short *pushort;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 2 ; i++ ) tab2[2-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 2 ; i++ ) tab2[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<2; i++) tab2[i]=pbuffer->at(startByte+i);
//   *(tab2) = qFromLittleEndian(*(tab2));
  pushort = reinterpret_cast<unsigned short *>(tab2);
  return *pushort;
};

//! Return the buffer value as as Unsigned short integer (int8)
short bufferToShort( int startByte , boost::shared_ptr<ublox::buffer_t> pbuffer )
{
  char tab2[2];
  short *pshort;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 2 ; i++ ) tab2[2-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 2 ; i++ ) tab2[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<2; i++) tab2[i]=pbuffer->at(startByte+i);
//   *(tab2) = qFromLittleEndian(*(tab2));
  pshort = reinterpret_cast<short *>(tab2);
  return *pshort;
};

short bufferToShort( int startByte , ublox::buffer_t *pbuffer )
{
  char tab2[2];
  short *pshort;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 2 ; i++ ) tab2[2-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 2 ; i++ ) tab2[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<2; i++) tab2[i]=pbuffer->at(startByte+i);
//   *(tab2) = qFromLittleEndian(*(tab2));
  pshort = reinterpret_cast<short *>(tab2);
  return *pshort;
};

//! Returns the bufer as an Unsigned Long Integer (uint16) ;
unsigned long bufferToULong(int startByte, boost::shared_ptr<ublox::buffer_t> pbuffer)
{
  char tab4[4];
  unsigned long *pULong;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 4 ; i++ ) tab4[4-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 4 ; i++ ) tab4[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab4[i]=pbuffer->at(startByte+i);
//   *(tab4) = qFromLittleEndian(*(tab4));
  pULong = reinterpret_cast<unsigned long *>(tab4);
  return *pULong;
};

unsigned long bufferToULong(int startByte, ublox::buffer_t *pbuffer)
{
  char tab4[4];
  unsigned long *pULong;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 4 ; i++ ) tab4[4-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 4 ; i++ ) tab4[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab4[i]=pbuffer->at(startByte+i);
//   *(tab4) = qFromLittleEndian(*(tab4));
  pULong = reinterpret_cast<unsigned long *>(tab4);
  return *pULong;
};

//! Returns the buffer value as an Signed long integer (int16)
long bufferToLong(int startByte, boost::shared_ptr<ublox::buffer_t> pbuffer)
{
  char tab4[4];
  long *plong;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 4 ; i++ ) tab4[4-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 4 ; i++ ) tab4[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab4[i]=pbuffer->at(startByte+i);
//   *(tab4) = qFromLittleEndian(*(tab4));
  plong = reinterpret_cast<long *>(tab4);
  return *plong;
};

long bufferToLong(int startByte, ublox::buffer_t *pbuffer)
{
  char tab4[4];
  long *plong;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for ( int i = 0 ; i < 4 ; i++ ) tab4[4-i]=pbuffer->at(startByte+i);
  #else
    for ( int i = 0 ; i < 4 ; i++ ) tab4[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab4[i]=pbuffer->at(startByte+i);
//   *(tab4) = qFromLittleEndian(*(tab4));
  plong = reinterpret_cast<long *>(tab4);
  return *plong;
};

//! returns the buffer value as a float
float bufferToFloat(int startByte, boost::shared_ptr<ublox::buffer_t> pbuffer)
{
  char tab8[4];
  float *pdouble;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for (int i=0; i<4; i++) tab8[4-i]=pbuffer->at(startByte+i);
  #else
    for (int i=0; i<4; i++) tab8[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab8[i]=pbuffer->at(startByte+i);
//   *(tab8) = qFromLittleEndian(*(tab8));
  pdouble = reinterpret_cast<float *>(tab8);
  return *pdouble;
};

float bufferToFloat(int startByte, ublox::buffer_t *pbuffer)
{
  char tab8[4];
  float *pdouble;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for (int i=0; i<4; i++) tab8[4-i]=pbuffer->at(startByte+i);
  #else
    for (int i=0; i<4; i++) tab8[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<4; i++) tab8[i]=pbuffer->at(startByte+i);
//   *(tab8) = qFromLittleEndian(*(tab8));
  pdouble = reinterpret_cast<float *>(tab8);
  return *pdouble;
};

//! returns the buffer value as a double
double bufferToDouble(int startByte, boost::shared_ptr<ublox::buffer_t> pbuffer)
{
  char tab8[8];
  double *pdouble;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for (int i=0; i<8; i++) tab8[8-i]=pbuffer->at(startByte+i);
  #else
    for (int i=0; i<8; i++) tab8[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<8; i++) tab8[i]=pbuffer->at(startByte+i);
//   *(tab8) = qFromLittleEndian(*(tab8));
  pdouble = reinterpret_cast<double *>(tab8);
  return *pdouble;
};

double bufferToDouble(int startByte, ublox::buffer_t *pbuffer)
{
  char tab8[8];
  double *pdouble;
  #if ___BYTE_ORDER == __BIG_ENDIAN
    for (int i=0; i<8; i++) tab8[8-i]=pbuffer->at(startByte+i);
  #else
    for (int i=0; i<8; i++) tab8[i]=pbuffer->at(startByte+i);
  #endif
//   for (int i=0; i<8; i++) tab8[i]=pbuffer->at(startByte+i);
//   *(tab8) = qFromLittleEndian(*(tab8));
  pdouble = reinterpret_cast<double *>(tab8);
  return *pdouble;
};

//! extract the value of byte at pos iiin a char.
bool extractBit(char byte, int pos)
{
  return (byte >> pos) & 0x01;
}

std::bitset<8> bufferToX1( int startByte , boost::shared_ptr<ublox::buffer_t>  pbuffer )
{
  std::bitset<8> flag ;
  for ( int k = 0 ; k < 8 ; k++ ) flag[k] = extractBit( pbuffer->at(startByte) , k ) ;
  return flag ;
};

std::bitset<8> bufferToX1( int startByte , ublox::buffer_t * pbuffer )
{
  std::bitset<8> flag ;
  for ( int k = 0 ; k < 8 ; k++ ) flag[k] = extractBit( pbuffer->at(startByte) , k ) ;
  return flag ;
};


std::bitset<16> bufferToX2( int startByte , boost::shared_ptr<ublox::buffer_t>  pbuffer )
{
  std::bitset<16> flag ;
  int n = startByte ;
  for ( int k = 0 ; k < 16 ; k++ )
  {
    if ( k == 8 ) n++ ;
    flag[k] = extractBit( pbuffer->at(n) , k ) ;
  };
  return flag ;
};

std::bitset<16> bufferToX2( int startByte , ublox::buffer_t * pbuffer )
{
  std::bitset<16> flag ;
  int n = startByte ;
  for ( int k = 0 ; k < 16 ; k++ )
  {
    if ( k == 8 ) n++ ;
    flag[k] = extractBit( pbuffer->at(n) , k ) ;
  };
  return flag ;
};

std::bitset<32> bufferToX4( int startByte , boost::shared_ptr<ublox::buffer_t>  pbuffer )
{
  std::bitset<32> flag ;
  int n = startByte ;
  for ( int k = 0 ; k < 32 ; k++ )
  {
    if ( k == 8 ) n++ ;
    flag[k] = extractBit( pbuffer->at(n) , k ) ;
  };
  return flag ;
};

std::bitset<32> bufferToX4( int startByte , ublox::buffer_t * pbuffer )
{
  std::bitset<32> flag ;
  int n = startByte ;
  for ( int k = 0 ; k < 32 ; k++ )
  {
    if ( k == 8 ) n++ ;
    flag[k] = extractBit( pbuffer->at(n) , k ) ;
  };
  return flag ;
};

// std::bitset<32> bufferToX4( int startByte , ublox::buffer_t * pbuffer );


/*!
 *
 */
unsigned char extractSFID ( const long *DWRD )
{
  return ( unsigned char ) ( ( ( DWRD[1] ) &0x0000001C ) >>2 );
//     return (unsigned char)(((DWRD[1])&0x00000700)>>8);
}

/*!
 *
 */
unsigned short extractTOW ( const long *DWRD )
{
  return ( unsigned short ) ( ( ( DWRD[1] ) &0xFFFF80 ) >>7 );
}

/*!
 *
 */
unsigned short extractSVID ( const long *DWRD )
{
  return ( unsigned short ) ( ( ( DWRD[2] ) &0x1F8000 ) >>15 );
}

void UShortToBuffer( unsigned short val , unsigned int startByte , ublox::buffer_t * pbuffer )
{
    pbuffer->at( startByte ) = val & 0xff ;
    pbuffer->at( startByte+1 ) = ( val >> 8 ) & 0xff ;
} ;

void ShortToBuffer( short val , uint startByte , ublox::buffer_t * pbuffer )
{
    pbuffer->at( startByte ) = val & 0xff ;
    pbuffer->at( startByte+1 ) = ( val >> 8 ) & 0xff ;
} ;

void ULongToBuffer( uint val , uint startByte , ublox::buffer_t * pbuffer )
{
    pbuffer->at(startByte) = val & 0xff ;
    pbuffer->at(startByte+1) = ( val >> 8 ) & 0xff ;
    pbuffer->at(startByte+2) = ( val >> 16 ) & 0xff ;
    pbuffer->at(startByte+3 ) = ( val >> 24 ) & 0xff ;
} ;

void LongToBuffer( int val , uint startByte , ublox::buffer_t * pbuffer )
{
    pbuffer->at(startByte) = val & 0xff ;
    pbuffer->at(startByte+1) = ( val >> 8 ) & 0xff ;
    pbuffer->at(startByte+2) = ( val >> 16 ) & 0xff ;
    pbuffer->at(startByte+3 ) = ( val >> 24 ) & 0xff ;

};


void FloatToBuffer( float val , uint startByte , ublox::buffer_t * pbuffer )
{
  std::stringstream sstream ;
  sstream << val ;
  std::string c_str = sstream.str() ;
  for ( uint k = 0 ; k < 4 ; k++ ) pbuffer->at(startByte+k) = c_str.at(k) ;
};

void DoubleToBuffer( double val , uint startByte , ublox::buffer_t * pbuffer )
{
  std::stringstream sstream ;
  sstream << val ;
  std::string c_str = sstream.str() ;
  for ( uint k = 0 ; k < 8 ; k++ ) pbuffer->at(startByte+k) = c_str.at(k) ;
};

void X1ToBuffer( std::bitset<8> val , uint startByte , ublox::buffer_t * pbuffer )
{
  unsigned int v = val.to_ulong() ;
  pbuffer->at(startByte) = v & 0xff ;
};

void X2ToBuffer( std::bitset<16> val , uint startByte , ublox::buffer_t * pbuffer )
{
  unsigned int v = val.to_ulong() ;
  pbuffer->at(startByte) = v & 0xff ;
  pbuffer->at(startByte+1) = ( v >> 8 ) & 0xff ;
} ;

void X4ToBuffer( std::bitset<32> val , uint startByte , ublox::buffer_t * pbuffer )
{
  ULongToBuffer( val.to_ulong() , startByte , pbuffer );
};

void UCharToBuffer( unsigned char val , unsigned int startByte , ublox::buffer_t * p_buffer )
{
  p_buffer->at(startByte) = static_cast<char>(val) ;
} ;
