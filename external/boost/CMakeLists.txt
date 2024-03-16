cmake_minimum_required(VERSION 3.14)

set( BOOST_VERSION 1.58.0)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(
    Boost ${BOOST_VERSION} REQUIRED COMPONENTS 
        filesystem
) 
message(STATUS "Boost Version: ${Boost_VERSION}")

if(Boost_FOUND)
    set_target_properties(  Boost::boost
                            Boost::filesystem
        PROPERTIES IMPORTED_GLOBAL TRUE)
endif()

target_link_libraries(ShLauncherLibrary PUBLIC Boost::filesystem)