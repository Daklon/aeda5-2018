cmake_minimum_required(VERSION 2.8)

project(aeda5-2018)
set( CMAKE_CXX_FLAGS "-std=c++11 -g -fpermissive")
enable_testing()
#especificamos el directorio de libs
include_directories(include)

#comando con wildcards para añadir archivos
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include(CTest)

# does the application run
add_test (projectRuns ${PROJECT_NAME})

