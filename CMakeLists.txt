cmake_minimum_required(VERSION 3.16)
project(LibraryProject C)

set(CMAKE_C_STANDARD 99)

add_executable(LibraryProject books.c books.h local_library.c "aditional fuctions.c" local_library.h functionsOnBookList.c functionsOnBookList.h main.c functionsOnBookList.c)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -pedantic -Wconversion")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
