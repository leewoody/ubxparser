/*!
 * \file UbxAidEphParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file contains the declaration for ublox::aid::HuiParser
 * 
 */

#ifndef __UBLOX_AID_EPH_PARSER__
#define __UBLOX_AID_EPH_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox 
{
   
   namespace aid 
   {
      
      class EphParser : public ublox::TempParserBase<EphData>
      {
      public :
	 EphParser() : ublox::TempParserBase<EphData>(AID,EPH,true) {};
	 void processFrame(  boost::shared_ptr<buffer_t> pbuffer );
         buffer_t generatePollRequest(U1 svid);
      } ;
      
   } ;
   
};

#endif