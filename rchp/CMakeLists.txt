cmake_minimum_required(VERSION 3.15)
project(rchp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    message(STATUS "Using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
endif()

find_package(pybind11 REQUIRED)

find_package(cpr CONFIG REQUIRED)

pybind11_add_module(crchp 
    rchp/crchp.cc
)

target_include_directories(crchp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/rchp
    ${CMAKE_CURRENT_SOURCE_DIR}/rchp/include
)

target_link_libraries(crchp PRIVATE cpr::cpr)

install(TARGETS crchp DESTINATION rchp)
