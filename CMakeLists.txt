cmake_minimum_required(VERSION 3.8)
project(sensibo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp manager/SensiboManager.cpp manager/SensiboManager.h  define.h define.h manager/SensiboDevice.cpp manager/SensiboDevice.h manager/SensiboAcState.cpp manager/SensiboAcState.h)
add_executable(sensibo ${SOURCE_FILES})

find_package(OpenSSL)
target_link_libraries(sensibo ${EXECUTABLE_NAME} ${OPENSSL_LIBRARIES})

