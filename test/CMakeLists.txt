cmake_minimum_required(VERSION 3.2)
project(divider_tests)

add_subdirectory(lib/googletest)

include_directories(${DIVISION_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/tuple_tests.cpp)

add_executable(tuple_tests ${SOURCE_FILES})
target_link_libraries(tuple_tests primatives gtest)
install(TARGETS tuple_tests DESTINATION bin)

