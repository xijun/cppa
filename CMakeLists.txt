cmake_minimum_required(VERSION 3.2)
project(cppa)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -std=c++14 -ldl -g3")
set(SOURCE_FILES
    src/label.hh
    src/label.hxx
    src/polynomial.hh src/polynomial.hxx src/main.cc)

find_package(Boost 1.40 COMPONENTS program_options system REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_custom_target(check ALL)
add_custom_command(TARGET POST_BUILD check COMMAND if [ -e cppa ]\; then ./cppa\; else make\; fi)

add_executable(cppa ${SOURCE_FILES})

target_link_libraries(cppa ${Boost_LIBRARIES})

