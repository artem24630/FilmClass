cmake_minimum_required(VERSION 3.17)
project(FilmClass)

set(CMAKE_CXX_STANDARD 14)

include_directories(FilmClass)

add_executable(FilmClass
        FilmClass/Film.h
        FilmClass/Main.cpp FilmClass/Film.cpp FilmClass/MyArray.cpp FilmClass/MyArray.h FilmClass/MyString.cpp FilmClass/MyString.h)
