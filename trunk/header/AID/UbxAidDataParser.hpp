/*!
 * \file UbxAidDataParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines a aid::ReqParser
 *
 */

#ifndef __UBLOX_AID_DATA_PARSER__
#define __UBLOX_AID_DATA_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{

  namespace aid
  {

     /*!
      * \brief Poll GPS initial aiding data
      *
      * If this poll is received, the messages AID-INI, AID-HUI, AID-EPH and AID-ALM are sent.
      */

  class DataParser : public ublox::TempParserBase<NullData>
  {
  public :
    DataParser() : ublox::TempParserBase<NullData>( AID , DATA , true ) { };
    void processFrame(  boost::shared_ptr<buffer_t> pbuff ) { doneProcessing() ; } ;

  } ;


  };

};

#endif