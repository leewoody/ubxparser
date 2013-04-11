/*!
 * \file UbxRxmReqParser.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines a aid::ReqParser
 *
 */

#ifndef __UBLOX_RXM_PMREQ_PARSER__
#define __UBLOX_RXM_PMREQ_PARSER__

#include "UbxDefinitions.hpp"
#include "base/UbxParserBase.hpp"

namespace ublox
{

  namespace rxm
  {

  class PmreqParser : public ublox::TempParserBase<PmreqData>
  {
  public :
    PmreqParser() : ublox::TempParserBase<PmreqData>( RXM , PMREQ , true ) { };
    void processFrame(  boost::shared_ptr<buffer_t> pbuff ) { doneProcessing() ; } ;
    buffer_t generatePmRequest( U4 duration , bool backup ) ;
  } ;


  };

};

#endif