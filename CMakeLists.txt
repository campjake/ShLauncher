cmake_minimum_required(VERSION 3.14)
project(shLauncher)

# GoogleTest requires at least C++20!!!
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(library)

add_executable(
  game_test
  tests/GameTest.cc
  tests/GameDirTest.cc
  tests/LauncherTest.cc
)
target_link_libraries(
  game_test
  GTest::gtest_main
  ShLauncherLibrary
)

target_compile_features(game_test PUBLIC cxx_std_20)

include(GoogleTest)
gtest_discover_tests(game_test)