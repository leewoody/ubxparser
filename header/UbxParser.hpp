#ifndef __UBLOX_UBX_PARSER__
#define __UBLOX_UBX_PARSER__

#include <iostream>
#include <vector>

#include "UbxDefinitions.hpp"
#include "base/ValueMap.hpp"

#include "ACK/UbxAckParser.hpp"
#include "AID/UbxAidParser.hpp"
#include "NAV/UbxNavParser.hpp"
#include "RXM/UbxRxmParser.hpp"
#include "TIM/UbxTimParser.hpp"


namespace ublox
{

/*!
 * Take a UBX frame as input and populate the data object from
 * the GPStk
 *
 * \todo Gestion des fichiers de config
 * \todo Finir le décodage des trames
 * \todo Encodage des trames de config (Mineur)
*/

class UbxParser : public ublox::ParserBase
{

public :
    /*!
     * \brief Default Constructor
     * This one does nothing
     */
    UbxParser() ;

    /*!
     * \brief Default Destructor
     * Deletes the parsers and data structures.
     */
    ~UbxParser() ;

    /*!
     * \brief Proccessing input buffer
     * If no buffer is given then the internalBuffer is processed.
     * Computes :
     * - Check Messsage size
     * - Check CRC
     */
//   void processFrame ( buffer_t * pbuffer = 0 );
    void processFrame ( shared_ptr<buffer_t> pbuffer );

    /*!
     * \brief Append to internal buffer
     * Appends the input buffer to the internal buffer. This function
     * must becaled prior to processFrame() ;
     */
    void addFromSerialPort ( buffer_t * buf ) ;

    /*!
     * \brief Connects a function to a given signal
     *
     * This function connect a external function to the signal emitted  by the parser
     * identified by \param msg_class and \param msg_id.
     * If the parser doesn't exists. The function attemps to create the parser.
     *
     * \param msg_class The class of the considered message
     * \param msg_id The id of the considered message
     * \return boost::signals2::connection to the parser
     *
     */
    boost::signals2::connection connectToParser( const I1 & m_cl , const I1 & m_id , const slot_t & slot ) ;

    /*!
     * \brief Accessor to data
     * \return a boost::shared_ptr<T> to the data.
     * \throw ublox::UnknowData
     */
    template <typename T> boost::shared_ptr<T> getData( const I1 & m_cl , const I1 & m_id ) throw()
    {
        MSG_ID id = getMsgUniqueId(m_cl,m_id) ;
        return dynamic_pointer_cast<T>( dataMap.get(id) ) ;
    } ;

    /*!
     * \brief Accessor to parser
     * \return a boost::shared_ptr<T> to the parser
     * \throw ublox::UnknowParser
     */
    template <typename T> boost::shared_ptr<T> getParser( const I1 & m_cl , const I1 & m_id ) throw()
    {
        MSG_ID id = getMsgUniqueId(m_cl,m_id) ;
        return dynamic_pointer_cast<T>( parserMap.get(id) ) ;
    } ;

    /*!
    * Creates a parser and add it to the parserMap
    */
    template <class T> boost::shared_ptr<T> createParser( const MSG_ID & id )
    {
        boost::shared_ptr<T> p( new T() );
        parserMap.set( id , p );
        dataMap.set( id , p->data() );
        return p ;
    }

private :

    /*!
     * Std::map of active parsers
     */
    ublox::ValueMap<parsers_p> parserMap ;

    /*!
     * std::map of data structure
     */
    ublox::ValueMap<datas_p> dataMap ;

};

};

#endif
