cmake_minimum_required(VERSION 3.2)
project(ray_tracer)

add_subdirectory(primatives)
set(SOURCE_FILES main.cpp)

add_executable(ray_tracer ${SOURCE_FILES})
target_link_libraries(ray_tracer primatives range_v3)
install(TARGETS ray_tracer DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})

