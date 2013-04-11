/*!
 * \file UbxAidHuiParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file contains the declaration for ublox::aid::HuiParser
 *
 */

#include "AID/UbxAidHuiParser.hpp"

using namespace ublox ;
using namespace ublox::aid ;

void HuiParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->health = bufferToX4(i0,pbuffer);
  pToData->utcA[0] = bufferToDouble(i0+4,pbuffer);
  pToData->utcA[1] = bufferToDouble(i0+12,pbuffer);
  pToData->utcTOW = bufferToLong(i0+20,pbuffer);
  pToData->utcWNT = bufferToShort(i0+24,pbuffer);
  pToData->utcLS = bufferToShort(i0+26,pbuffer);
  pToData->utcWNF = bufferToShort(i0+28,pbuffer);
  pToData->utcDN = bufferToShort(i0+30,pbuffer);
  pToData->utcLSF = bufferToShort(i0+32,pbuffer);
  pToData->utcSpare = bufferToShort(i0+34,pbuffer);
  for ( int k = 0 ; k < 4 ; k++ )
  {
    pToData->klobA[k] = bufferToFloat( i0+34+k*4 , pbuffer ) ;
    pToData->klobB[k] = bufferToFloat( i0+52+k*4 , pbuffer ) ;
  };
  pToData->flags = bufferToX4( i0+68 , pbuffer ) ;
  pToData->unlock() ;
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;