#include "UbxParser.hpp"

using namespace ublox ;

/*!
 * Default constructor
 */
UbxParser::UbxParser() : ParserBase()
{
    internalBuffer = shared_ptr<buffer_t>( new buffer_t() ) ;
    this->startThread();
} ;

/*!
 * Default Destructor
 */
UbxParser::~UbxParser()
{
} ;

/*!
 * Appends data from a serial port
 */
void UbxParser::addFromSerialPort ( buffer_t * rsBuff )
{
    if ( VERBOSE_PARSER ) std::cout << "Copying data to internal buffer" << std::flush ;
    boost::lock_guard<boost::mutex> lock(processMutex) ;
    for ( uint k = 0 ; k != rsBuff->size() ; k++ )
    {
        internalBuffer->push_back( rsBuff->at ( k ) );
    };
    availableData.notify_all();
    if ( VERBOSE_PARSER ) std::cout << "--> done" << std::endl ;
} ;

void UbxParser::processFrame ( shared_ptr<buffer_t> pbuffer )
{
    int nmsg = 0 ;

    while ( pbuffer->size() > ublox::HEADER_SIZE )
    {
        if ( ( pbuffer->at(0) == SYNC1 ) && ( pbuffer->at(1) == SYNC2 )  )
        {

            unsigned short msg_size = messageSize ( pbuffer );
            if ( msg_size <= pbuffer->size() )
            {
                MSG_ID id = ublox::getMsgUniqueId( pbuffer->at(2) , pbuffer->at(3) ) ;
                std::string str_id = ublox::MsgIdAsString( pbuffer->at(2) , pbuffer->at(3) ) ;
                if ( VERBOSE_PARSER ) std::cout << " New message detected -> MSG ID = " << str_id << " (" << id << ")" << std::endl ;
                boost::shared_ptr<buffer_t> tempBuffer(new buffer_t( pbuffer->begin() , pbuffer->begin()+msg_size ) );
                pbuffer->erase( pbuffer->begin() , pbuffer->begin()+msg_size );
                // Check CRC of message
                // if ok -> send to parser
                // if nok -> drop message
                if ( checkCRC ( tempBuffer ) )
                {
                    try
                    {
                        parsers_p parser = parserMap.get(id);
                        if ( !parser->asNoConnection() )
                        {
                            parser->setBuffer(tempBuffer);
//                           parser->processFrame( tempBuffer );
                        }
                        else if ( VERBOSE_PARSER ) std::cout << str_id << " dropped (useless)"<< std::endl ;
                    }
                    catch ( ublox::UnsetValue )
                    {
                        if ( VERBOSE_PARSER ) std::cout << str_id << " dropped (no parser)"<< std::endl ;
                    } ;
                }
                else
                {
                    if ( VERBOSE_PARSER ) std::cout << str_id << " --> CRC Check failed <--" << std::endl ;
                } // if CRC
                nmsg++ ;
            }
            else
            {
                break ;
            }
        }
        else
        {
            pbuffer->erase ( pbuffer->begin() ) ;
        } // if ( newmsg)
    } // while()
};

boost::signals2::connection UbxParser::connectToParser( const I1 & m_cl , const I1 & m_id , const slot_t & slot )
{
    // tries to connect to an existing parser
    MSG_ID id = ublox::getMsgUniqueId( m_cl , m_id ) ;
    parsers_p parser ;
    try
    {
        parser = parserMap.get(id);
    }
    catch ( ublox::UnsetValue )
    {
        if ( VERBOSE_PARSER ) {
            std::cout << "Parser doesn't exist --> creating parser " << id << std::endl ;
        } ;
        if ( id == getMsgUniqueId(ACK,0) )
            parser = createParser<ack::Parser>(id) ;

        else if ( id == getMsgUniqueId(AID,aid::ALM) )
            parser = createParser<aid::AlmParser>(id) ;
        else if ( id == getMsgUniqueId(AID,aid::DATA) )
            parser = createParser<aid::DataParser>(id) ;
        else if ( id == getMsgUniqueId(AID,aid::EPH) )
            parser = createParser<aid::EphParser>(id) ;
        else if ( id == getMsgUniqueId(AID,aid::HUI) )
            parser = createParser<aid::HuiParser>(id) ;
        else if ( id == getMsgUniqueId(AID,aid::INI) )
            parser = createParser<aid::IniParser>(id) ;
        else if ( id == getMsgUniqueId(AID,aid::REQ) )
            parser = createParser<aid::ReqParser>(id) ;

        else if ( id == getMsgUniqueId(NAV,nav::AOPSTATUS) )
            parser = createParser<nav::AopstatusParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::CLOCK) )
            parser = createParser<nav::ClockParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::DOP) )
            parser = createParser<nav::DopParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::DGPS) )
            parser = createParser<nav::DgpsParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::EKFSTATUS) )
            parser = createParser<nav::EkfstatusParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::POSECEF) )
            parser = createParser<nav::PosecefParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::POSLLH) )
            parser = createParser<nav::PosllhParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::SBAS) )
            parser = createParser<nav::SbasParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::SOL) )
            parser = createParser<nav::SolParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::STATUS) )
            parser = createParser<nav::StatusParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::SVINFO) )
            parser = createParser<nav::SvinfoParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::TIMEGPS) )
            parser = createParser<nav::TimegpsParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::TIMEUTC) )
            parser = createParser<nav::TimeutcParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::VELECEF) )
            parser = createParser<nav::VelecefParser>(id) ;
        else if ( id == getMsgUniqueId(NAV,nav::VELNED) )
            parser = createParser<nav::VelnedParser>(id) ;

        else if ( id == getMsgUniqueId(RXM,rxm::RAW) )
            parser = createParser<rxm::RawParser>(id) ;
        else if ( id == getMsgUniqueId(RXM,rxm::SFRB) )
            parser = createParser<rxm::SfrbParser>(id) ;
        else if ( id == getMsgUniqueId(RXM,rxm::SVSI) )
            parser = createParser<rxm::SvsiParser>(id) ;
        else if ( id == getMsgUniqueId(RXM,rxm::ALM) )
            parser = createParser<rxm::AlmParser>(id) ;
        else if ( id == getMsgUniqueId(RXM,rxm::EPH) )
            parser = createParser<rxm::EphParser>(id) ;
        else if ( id == getMsgUniqueId(RXM,rxm::PMREQ) )
            parser = createParser<rxm::PmreqParser>(id) ;

        else throw( ublox::UnknowParser() );

        parser->startThread() ;
    } ;
    boost::signals2::connection c = parser->connectTo( slot );
    return c ;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0;
