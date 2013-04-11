/*!
 * \file UbxAidHuiParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines the parser for AID-HUI data
 *
 */

#ifndef __UBLOX_AID_HUI_PARSER__
#define __UBLOX_AID_HUI_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{

  namespace aid
  {

    class HuiParser : public ublox::TempParserBase<HuiData>
    {
    public :
      HuiParser() : ublox::TempParserBase<HuiData>( AID , HUI , true ) { } ;
      void processFrame(  boost::shared_ptr<buffer_t> );
    };

  } ;

};

#endif