
cmake_minimum_required( VERSION 2.8 )

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_COMPILER /usr/local/bin/g++-4.9 )
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11 )

project ( GCJ2015_R1C CXX )

file( GLOB SRCS *.cpp )
foreach( src ${SRCS} )
    get_filename_component( exec ${src} NAME_WE )
    add_executable( ${exec} ${src} )
endforeach( src ${srcs} )

