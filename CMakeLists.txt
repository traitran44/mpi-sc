cmake_minimum_required(VERSION 3.17)
project(mpi_sc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
FILE(GLOB SOURCE ./src/*.cpp)
add_executable(mpi_sc ${SOURCE} src/fir.cpp)
target_include_directories(mpi_sc PUBLIC lib/include)
target_include_directories(mpi_sc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/include
        )
target_link_libraries(mpi_sc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsystemc.so)
