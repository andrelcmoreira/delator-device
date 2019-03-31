cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_NAME "delator")
set(HEADERS_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(SOURCES_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

include_directories(
    ${HEADERS_DIR}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(HEADERS
    ${HEADERS_DIR}/gps_device.h
    ${HEADERS_DIR}/gprs_device.h
    ${HEADERS_DIR}/microphone_device.h
    ${HEADERS_DIR}/thread_pool.h
    ${HEADERS_DIR}/daemon.h
)

set(SOURCES
    ${SOURCES_DIR}/gps_device.cc
    ${SOURCES_DIR}/gprs_device.cc
    ${SOURCES_DIR}/microphone_device.cc
    ${SOURCES_DIR}/thread_pool.cc
    ${SOURCES_DIR}/daemon.cc
    ${SOURCES_DIR}/app.cc
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} boost_program_options)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${PROJECT_NAME})
