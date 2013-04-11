/*!
 * \file UbxAidReqParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines a aid::ReqParser
 *
 */

#ifndef __UBLOX_AID_REQ_PARSER__
#define __UBLOX_AID_REQ_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{

  namespace aid
  {

  class ReqParser : public ublox::TempParserBase<NullData>
  {
  public :
    ReqParser() : ublox::TempParserBase<NullData>( AID , REQ , true ) { };
    void processFrame(  boost::shared_ptr<buffer_t> pbuff ) { doneProcessing() ; } ;

  } ;


  };

};

#endif