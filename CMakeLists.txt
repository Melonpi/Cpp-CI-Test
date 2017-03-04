cmake_minimum_required(VERSION 3.0)
project(CPP_CI_TEST)

set(INC_FILES include/add.hpp)
set(SRC_FILES src/add.cpp)
set(TEST_FILES test/test.cpp)
include_directories(include)

set(Boost_USE_STATIC_LIBS on)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(-std=c++11 -stdlib=libc++ -O3 -Wall)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(-std=c++11 -O3 -Wall -Wextra)
endif()

add_executable(exe ${SRC_FILES} ${TEST_FILES} ${INC_FILES})
target_link_libraries(exe ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()
add_test(myTest exe)