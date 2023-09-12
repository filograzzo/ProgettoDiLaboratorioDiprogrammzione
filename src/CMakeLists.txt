cmake_minimum_required(VERSION 3.26)
project(ProgettiDiLaboratorioDiProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProgettiDiLaboratorioDiProgrammazione main.cpp
        Note.cpp
        Note.h
        Folders.cpp
        Folders.h
        FavouriteFolders.cpp
        FavouriteFolders.h)
