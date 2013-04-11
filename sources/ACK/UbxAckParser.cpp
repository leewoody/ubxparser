#include "ACK/UbxAckParser.hpp"

using namespace ublox ;
using namespace ublox::ack ;
using namespace boost ;

// Parser::Parser( ParserBase * p ) : ParserBase(ACK,0,p)
// {
//   Data_p data_t;
//   try
//   {
//     data_t = getData(msg_cl,msg_id);
//   }
//   catch ( UnknowData & e )
//   {
//     data_t = createData<AckData>() ;
//   }
//   data = dynamic_pointer_cast<AckData>(data_t) ;
//
//
// //   MapData_t::iterator it = pToData->find( ACK ) ;
// //   if ( it != pToData->end() )
// //     data = static_cast<AckData*>((*it).second) ;
// //   else
// //     {
// //       data = new AckData() ;
// //       this->insertData( ACK , 0 , data );
// //     }
// } ;
//
// //! Identify the frame and sent to the correct parser
// void Parser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
// {
// //    std::cout << "rxm::Parser -> processing data" << std::endl ;
//   char msgId = pbuf->at(3) ;
// //     char clssId = pbuf->at(2) ;
//
//   if ( msgId == ack::ACK )
//     data->acknoledged = true ;
//   else if ( msgId == ack::NAK )
//     data->acknoledged = false ;
//   else return ;
//   data->clsID = bufferToChar(HEADER_SIZE,pbuf);
//   data->msgID = bufferToChar(HEADER_SIZE+1,pbuf);
//   doneProcessing() ;
// }

void Parser::processFrame(  boost::shared_ptr<buffer_t> pbuf )
{
  char msgId = pbuf->at(3) ;

  pToData->lock() ;
  if ( msgId == ack::ACK )      pToData->acknoledged = true ;
  else if ( msgId == ack::NAK ) pToData->acknoledged = false ;
  else return ;
  pToData->clsID = bufferToChar(HEADER_SIZE,pbuf.get());
  pToData->msgID = bufferToChar(HEADER_SIZE+1,pbuf.get());
  pToData->unlock() ;

  doneProcessing() ;
}
