cmake_minimum_required( VERSION 2.8 )

project( Perception )

set( PROJ_NAME "Perception" )

set( PROJ_SOURCES
    "PerceptionDemo.cpp"
    "PerceptionEvent.cpp"
    "data/Composite.cpp"
    "data/DumpVisitor.cpp"
    "data/JsonVisitor.cpp"
    "collectors/NetworkCollector.cpp"
    "collectors/SystemCollector.cpp"
    "collectors/Linux/CollectorFactoryLinux.cpp"
    "collectors/Linux/LinuxNetworkCollector.cpp" )

set( PROJ_INCLUDES
	"."
	"collectors"
    "collectors/Linux"
    "data" )

set( PROJ_PATH ${CMAKE_SOURCE_DIR} )
set( PROJ_OUT_PATH ${CMAKE_BINARY_DIR} )

include_directories( ${PROJ_INCLUDES} )
add_executable( ${PROJ_NAME} ${PROJ_SOURCES} )
