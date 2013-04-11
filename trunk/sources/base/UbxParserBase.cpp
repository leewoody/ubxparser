#include "base/UbxParserBase.hpp"

using namespace ublox ;

/*!
 * Default Constructor
 */
ParserBase::ParserBase() :
        msg_cl(0) ,
        msg_id(0) ,
        pollable(false)
{

};

/*!
 * Extended constructor
 */
ParserBase::ParserBase( const char & mcl , const char & mid , bool poll ) :
        msg_cl(mcl),
        msg_id(mid),
        pollable(poll)
{
    std::cout << "Creating Parser for " << MsgIdAsString(msg_cl,msg_id) << " (" << id() << ")" << std::endl ;
} ;

ParserBase::~ParserBase()
{
    std::cout << "Deleting Parser for " << MsgIdAsString(msg_cl,msg_id) << " (" << id() << ")" << std::endl ;
}

void ParserBase::setBuffer( boost::shared_ptr<buffer_t> pbuffer )
{
    boost::lock_guard<boost::mutex> lock(processMutex) ;
    internalBuffer = pbuffer ;
    availableData.notify_all();
};

void ParserBase::startThread()
{
    processThread = boost::thread( &ublox::ParserBase::run , this ) ;
}

void ParserBase::debug() const
{
    if (VERBOSE_PARSER)
      std::cout << ublox::MsgIdAsString(msg_cl,msg_id) << "(" << id() << ") processed" << std::endl ;
} ;

buffer_t ParserBase::generatePollRequest( const char & m_cl , const char & m_id) const
{
    buffer_t buf ;
    if ( pollable )
    {
        buf.assign( HEADER_SIZE+CRC_SIZE , char(0) );
        buf[0] = SYNC1 ;
        buf[1] = SYNC2 ;
        buf[2] = msg_cl ;
        buf[3] = msg_id ;
        buf[4] = 0 ;
        buf[5] = 0 ;
        computeCRC( buf[6] , buf[7] , &buf );
    }
    return buf ;
} ;

signal_t * ParserBase::done()
{
    return &doneProcessing ;
};

/*!
 * \brief return true if the parser as no connection
 */
bool ParserBase::asNoConnection() const
{
    return doneProcessing.empty() ;
};

//! \brief Return data ID :
MSG_ID ParserBase::id() const
{
    return ublox::getMsgUniqueId(msg_cl,msg_id) ;
};

boost::signals2::connection ParserBase::connectTo( const slot_t & slot )
{
    boost::signals2::connection c = doneProcessing.connect( slot );
    return c ;
} ;

void ParserBase::run()
{
    while ( 1 )
    {
        boost::unique_lock<boost::mutex> lock(processMutex) ;
        availableData.wait(lock);
        if ( VERBOSE_PARSER ) std::cout << "Processing MSG Id : " << id() << "(" << internalBuffer->size() << ")" << std::endl ;
        if ( internalBuffer ) processFrame(internalBuffer) ;
        if ( VERBOSE_PARSER ) std::cout << "Done MSG Id : " << id() << std::endl ;
    }
}
