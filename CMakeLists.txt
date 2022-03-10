cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

# aux_source_directory(./src/multiple SRCS)
# add_executable(${PROJECT_NAME} ${SRCS})

add_executable(${PROJECT_NAME} study/BitOperation/eor.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
