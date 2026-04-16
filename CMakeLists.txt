cmake_minimum_required(VERSION 4.2)
project(knihovna C)

set(CMAKE_C_STANDARD 17)

add_executable(knihovna main.c
        vstup_vystup.c
        vstup_vystup.h
        kniha.c
        kniha.h
        ctenar.c
        ctenar.h)
