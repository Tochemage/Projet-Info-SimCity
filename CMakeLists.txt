cmake_minimum_required(VERSION 3.21)
project(v1 C)

set(CMAKE_C_STANDARD 99)

add_executable(v1 main.c Header.h Allegro.c Menu.c initstrcut.c)

target_link_libraries(v1 mingw32 alleg44)

