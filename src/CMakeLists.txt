cmake_minimum_required(VERSION 2.8)

project(impl)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-W -Wall -Werror)
endif()

# GSL
add_definitions(-DGSL_THROW_ON_CONTRACT_VIOLATION)

include_directories(deps)
include_directories(lib)

add_subdirectory(td3)
add_subdirectory(td4)

add_subdirectory(lib)

enable_testing()
add_subdirectory(test)
