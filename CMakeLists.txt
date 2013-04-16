PROJECT( UbxParser )

cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
SET( CMAKE_VERBOSE_MAKEFILE 0 )
SET( CMAKE_CXX_FLAGS "-Wall -msse3 -mssse3 -msse4 -m64 -O3" ) #Disable pragma warning from GPSTk
set (UbxParser_VERSION_MAJOR 2)
set (UbxParser_VERSION_MINOR 3)
set (UbxParser_VERSION_PATCH 16)
set( CMAKE_BUILD_TYPE Release )

# Looking for QtCore ==> QtEndian (à supprimer !)
# FIND_PACKAGE( Qt4 COMPONENTS QtCore REQUIRED )
# INCLUDE( ${QT_USE_FILE} )
# INCLUDE_DIRECTORIES( ${QT_INCLUDE_DIR} )

# Find Boost pour les signaux
SET( Boost_USE_MULTITHREADED ON )
FIND_PACKAGE( Boost COMPONENTS thread signals )
LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS} )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIRS} )
MESSAGE ( STATUS ${Boost_LIBRARIES} )

# UbxParser sources
SET( SUB_DIRS
  sources
  sources/base
  sources/ACK
  sources/AID
  sources/CFG
  sources/ESF
  sources/INF
  sources/MON
  sources/TIM
  sources/RXM
  sources/NAV
)

FOREACH( DIR ${SUB_DIRS} )
  AUX_SOURCE_DIRECTORY( ${PROJECT_SOURCE_DIR}/${DIR} TMP_SOURCES )
  SET( UBX_SOURCES ${TMP_SOURCES} )
ENDFOREACH( DIR )

# Ubx Headers
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/header )

#build
# ADD_EXECUTABLE( test ${PROJECT_SOURCE_DIR}/main.cpp )
MESSAGE( STATUS "Build Type = ${CMAKE_BUILD_TYPE}" )
ADD_LIBRARY( UbxParser SHARED ${UBX_SOURCES} )
TARGET_LINK_LIBRARIES( UbxParser ${Boost_LIBRARIES} )
SET_TARGET_PROPERTIES( UbxParser PROPERTIES
    DEBUG_POSTFIX "_d"
    SOVERSION ${UbxParser_VERSION_MAJOR}.${UbxParser_VERSION_MINOR}.${UbxParser_VERSION_PATCH} )

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
MESSAGE( STATUS "Documentation can be build by : make doc" )
configure_file( ${PROJECT_SOURCE_DIR}/Doxyfile.in ${CMAKE_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)

INSTALL( DIRECTORY ${PROJECT_SOURCE_DIR}/doc/html
    DESTINATION /usr/share/doc/libubxparser-${UbxParser_VERSION_MAJOR}.${UbxParser_VERSION_MINOR}
    COMPONENT htmldoc )

endif(DOXYGEN_FOUND)

INSTALL(
  TARGETS UbxParser
  DESTINATION lib
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  COMPONENT libraries
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/UbxParser.hpp
	${PROJECT_SOURCE_DIR}/header/UbxDefinitions.hpp
  DESTINATION include/UbxParser
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/base/BufferConversion.hpp
	${PROJECT_SOURCE_DIR}/header/base/Exceptions.hpp
	${PROJECT_SOURCE_DIR}/header/base/UbxBaseData.hpp
	${PROJECT_SOURCE_DIR}/header/base/UbxDatatype.hpp
	${PROJECT_SOURCE_DIR}/header/base/UbxParserBase.hpp
	${PROJECT_SOURCE_DIR}/header/base/ValueMap.hpp
  DESTINATION include/UbxParser/base
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/ACK/UbxAckDefinitions.hpp
        ${PROJECT_SOURCE_DIR}/header/ACK/UbxAckParser.hpp
  DESTINATION include/UbxParser/ACK
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/AID/UbxAidDefinitions.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidAlmParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidDataParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidEphParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidHuiParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidIniParser.hpp
        ${PROJECT_SOURCE_DIR}/header/AID/UbxAidReqParser.hpp
  DESTINATION include/UbxParser/AID
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgDefinitions.hpp
	${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgMsgParser.hpp
	${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgRateParser.hpp
	${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgNav5Parser.hpp
	${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgSbasParser.hpp
	${PROJECT_SOURCE_DIR}/header/CFG/UbxCfgParser.hpp
  DESTINATION include/UbxParser/CFG
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/ESF/UbxEsfDefinitions.hpp
  DESTINATION include/UbxParser/ESF
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/INF/UbxInfDefinitions.hpp
  DESTINATION include/UbxParser/INF
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/MON/UbxMonDefinitions.hpp
  DESTINATION include/UbxParser/MON
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/NAV/UbxNavDefinitions.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavAopstatusParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavClockParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavDgpsParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavDopParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavEkfstatusParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavPosecefParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavPosllhParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavSbasParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavSolParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavStatusParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavSvinfoParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavTimegpsParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavTimeutcParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavVelecefParser.hpp
	${PROJECT_SOURCE_DIR}/header/NAV/UbxNavVelnedParser.hpp
  DESTINATION include/UbxParser/NAV
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmDefinitions.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmRawParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmSfrbParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmSvsiParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmAlmParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmEphParser.hpp
	${PROJECT_SOURCE_DIR}/header/RXM/UbxRxmPmreqParser.hpp
  DESTINATION include/UbxParser/RXM
  COMPONENT headers
)

INSTALL(
  FILES ${PROJECT_SOURCE_DIR}/header/TIM/UbxTimDefinitions.hpp
	${PROJECT_SOURCE_DIR}/header/TIM/UbxTimParser.hpp
	${PROJECT_SOURCE_DIR}/header/TIM/UbxTimSvinParser.hpp
	${PROJECT_SOURCE_DIR}/header/TIM/UbxTimTm2Parser.hpp
	${PROJECT_SOURCE_DIR}/header/TIM/UbxTimTpParser.hpp
	${PROJECT_SOURCE_DIR}/header/TIM/UbxTimVrfyParser.hpp
  DESTINATION include/UbxParser/TIM
  COMPONENT headers
)

IF( UNIX )
  INSTALL(
    FILES ${PROJECT_SOURCE_DIR}/FindUbxParser.cmake
    DESTINATION /usr/share/cmake-${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}/Modules
    COMPONENT cmakemodule
  )
ENDIF( UNIX )

SET( CPACK_GENERATOR "DEB" )
SET( CPACK_PACKAGE_DESCRIPTION_SUMMARY "A parsing toolbox for Ublox LEA-6T gps receiver" )
SET( CPACK_PACKAGE_DESCRIPTION "A parsing toolbox for Ublox LEA-6T gps receiver. This toolbox provides a parser for UBX-xxx type message (No NMEA processing)." )
SET( CPACK_DEBIAN_PACKAGE_MAINTAINER  "Clement Fouque" )
SET( CPACK_PACKAGE_VERSION_MAJOR ${UbxParser_VERSION_MAJOR} )
SET( CPACK_PACKAGE_VERSION_MINOR ${UbxParser_VERSION_MINOR} )
SET( CPACK_COMPONENTS_ALL libraries headers cmakemodule manpage htmldoc )
SET( CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-thread1.46.1, libboost-signals1.46.1" )

SET( CPACK_PACKAGE_NAME "libubxparser" )
set( CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}" )
find_program(DPKG_PROGRAM dpkg DOC "dpkg program of Debian-based systems")
if(DPKG_PROGRAM)
  execute_process(
    COMMAND ${DPKG_PROGRAM} --print-architecture
    OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
    OUTPUT_STRIP_TRAILING_WHITESPACE )
else(DPKG_PROGRAM)
  set( CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_NAME} )
endif(DPKG_PROGRAM)
SET( CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}_${CPACK_PACKAGE_VERSION}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}" )

include ( CPack )
