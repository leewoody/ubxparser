/*!
 * \file UbxRxmEphParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file contains the declaration for ublox::rxm::EphParser
 * 
 */

#ifndef __UBLOX_RXM_EPH_PARSER__
#define __UBLOX_RXM_EPH_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox 
{
   
   namespace rxm
   {
      
      class EphParser : public ublox::TempParserBase<EphData>
      {
      public :
	 EphParser() : ublox::TempParserBase<EphData>(RXM,EPH,true) {};
	 void processFrame(  boost::shared_ptr<buffer_t> pbuffer );
         buffer_t generatePollRequest(U1 svid);
      } ;
      
   } ;
   
};

#endif