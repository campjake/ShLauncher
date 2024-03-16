cmake_minimum_required(VERSION 3.14)

project(ShLauncher)

# Always use '-fPIC'/'-fPIE' option.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Make external libraries globally available
add_subdirectory(external)

#Create targets for building the (local) libraries
add_subdirectory(library)

#Create targets
# add_subdirectory(app)