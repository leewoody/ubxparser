#include "NAV/UbxNavSolParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void SolParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->week = bufferToUShort(i0+8,pbuffer);
  pToData->fTow = bufferToLong(i0+4,pbuffer);
  pToData->gpsFix = bufferToUChar(i0+10,pbuffer);
//     pToData->flags = bufferToUChar(i0+11,pbuffer);
  char f = bufferToChar( i0+11,pbuffer );
  for ( unsigned int k = 0 ; k < pToData->flags.size() ; k++ ) pToData->flags[k] = extractBit(f,k);
  pToData->Xecef = bufferToLong(i0+12,pbuffer);
  pToData->Yecef = bufferToLong(i0+16,pbuffer);
  pToData->Zecef = bufferToLong(i0+20,pbuffer);
  pToData->pAcc = bufferToULong(i0+24,pbuffer);
  pToData->vXecef = bufferToLong(i0+28,pbuffer);
  pToData->vYecef = bufferToLong(i0+32,pbuffer);
  pToData->vZecef = bufferToLong(i0+36,pbuffer);
  pToData->sAcc = bufferToULong(i0+40,pbuffer);
  pToData->pdop = bufferToUShort(i0+44,pbuffer);
  pToData->numSV = bufferToUChar(i0+47,pbuffer);
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
