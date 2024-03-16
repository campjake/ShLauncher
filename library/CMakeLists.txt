cmake_minimum_required(VERSION 3.14)

project(ShLauncher)

# An OBJECT-library, used only to compile common sources once
add_library(ShLauncherLibrary)     
target_sources(ShLauncherLibrary
    PRIVATE  "${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp"
    PRIVATE  "${CMAKE_CURRENT_SOURCE_DIR}/src/GameDir.cpp" 
    PUBLIC   "${CMAKE_CURRENT_SOURCE_DIR}/include/Game.hpp"
    PUBLIC   "${CMAKE_CURRENT_SOURCE_DIR}/include/GameDir.hpp"
)

#Required include search-paths
target_include_directories( ShLauncherLibrary
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features( ShLauncherLibrary
    PUBLIC cxx_std_14
)