cmake_minimum_required(VERSION 3.15)
project(rchp LANGUAGES CXX)

find_package(pybind11 REQUIRED)

find_package(cpr REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/rchp
    ${CMAKE_CURRENT_SOURCE_DIR}/rchp/include
)

pybind11_add_module(crchp 
    rchp/crchp.cc
)

target_link_libraries(crchp PRIVATE cpr::cpr)

install(TARGETS crchp DESTINATION rchp)