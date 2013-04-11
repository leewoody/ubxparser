#ifndef __UBX_TEMPLATE_PARSER_BASE__
#define __UBX_TEMPLATE_PARSER_BASE__

// STL Include
#include <vector>
#include <map>
#include <iostream>

// Boost
#include <boost/thread.hpp>

// Ubx Message definition
#include "UbxDefinitions.hpp"
#include "base/Exceptions.hpp"

using namespace boost ;

namespace ublox
{

class ParserBase
{
  //! Member function run by boost::thread
    void run() ;

    //! Processing thread associated to the parser
    boost::thread processThread ;

protected :
    //! UBX Class of the message
    char msg_cl ;

    //! UBX ID of the message
    char msg_id ;

    //! Message can be poll form receiver.
    bool pollable ;

    //! \brief Boost signal emitted when the frame is processed.
    //! This signal should be at the end of processFrame() reimplementation.
    signal_t doneProcessing ;

    boost::shared_ptr<buffer_t> internalBuffer ;

    boost::condition_variable availableData ;

    boost::mutex processMutex ;

public :
    //! Default Constructor
    ParserBase() ;

    //! Extended Constructor
    ParserBase( const char & mcl , const char & mid , bool poll = false ) ;

    virtual ~ParserBase() ;

    /*!
    * \brief Processing of the incoming buffer.
    * Must be overloaded by inherited class
    */
    virtual void processFrame (  boost::shared_ptr<buffer_t> pbuffer ) = 0 ;

    virtual void setBuffer( boost::shared_ptr<buffer_t> pbuffer ) ;

    void startThread() ;

    //! \brief Displays a debug string
    virtual void debug() const ;

    /*!
    * \brief generates the poll request message
    * This function generates the poll request message with an empty payload
    * if the message is pollable.
    */
    virtual buffer_t generatePollRequest( const char & m_cl = 0 , const char & m_id = 0 ) const ;

    /*!
     * \brief connect the parser to a slot
     * Connection is built using boost::signals::signal<>::extended_slot_type.
     * Thus, the slot has the management of its connection.
     */
    virtual boost::signals2::connection connectTo( const slot_t & slot ) ;

    /*!
     * Return a pointer to completion signal
     */
    signal_t * done();

    /*!
     * \brief return true if the parser as no connection
     */
    virtual bool asNoConnection() const ;

    //! \brief Return data ID :
    MSG_ID id() const ;

} ;


/*!
 * \brief Extended parser base
 * This is the template-base parser.
 * It includes additional function regarding the provided data-type
 */

template <class data_t> class TempParserBase : public ParserBase
{
public :
    //! Overloaded constructor.
    //! Creates the shared_ptr to the data
    TempParserBase ( const char & mcl , const char & mid , bool poll = false ) ;

    //! \brief Pointer to data
    virtual boost::shared_ptr<data_t> data() const ;

protected :
    //! \brief Handle for the parsed datas
    boost::shared_ptr<data_t> pToData ;

    //! Default constructor
    TempParserBase() ;
};


/*
 * Template functions implementation
 */
template <class data_t> TempParserBase<data_t>::TempParserBase() :
  ParserBase() ,
  pToData(0)
{

};

template <class data_t> TempParserBase<data_t>::TempParserBase ( const char & mcl , const char & mid , bool poll ) :
  ParserBase(mcl,mid,poll)
{
    pToData = boost::shared_ptr<data_t>( new data_t() ) ;
} ;

template <class data_t> boost::shared_ptr<data_t> TempParserBase<data_t>::data() const
{
    return pToData ;
} ;

};

#endif
