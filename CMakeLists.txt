cmake_minimum_required(VERSION 3.18)

project(util LANGUAGES C)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" DESTINATION "include")

include(CTest)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(USE_SANITIZERS "Compile tests with ASAN and UBSAN" OFF)

include_directories(PUBLIC "${CMAKE_SOURCE_DIR}/include")
add_compile_options(-Wall -Wextra -pedantic -Werror -O0 -g)

if (USE_SANITIZERS)
	add_compile_options(-fsanitize=undefined -fsanitize=address -fno-sanitize-recover=all)
	add_link_options(-fsanitize=undefined -fsanitize=address -fno-sanitize-recover=all)
endif()

file(GLOB Tests test/*.c)
foreach(Test IN ITEMS ${Tests})
	string(REGEX REPLACE "\.c$" "" TestName ${Test})
	string(REGEX REPLACE ".*test/" "test_" TestName ${TestName})
	add_executable(${TestName} ${Test})
	add_test(${TestName} ${TestName})
endforeach()

