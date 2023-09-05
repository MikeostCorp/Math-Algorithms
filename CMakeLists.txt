cmake_minimum_required(VERSION 3.0)

project(MathAlgo)

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SOURCES "main.cpp" "${SRC_DIR}/mathAlgo.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
