cmake_minimum_required(VERSION 3.10)
project(Lab5_6STL)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

add_executable(Lab_5_6
        Controller.cpp
        Controller.h
        RepositoryExceptions.cpp
        RepositoryExceptions.h
        CSVWatchlist.cpp
        CSVWatchlist.h
        HTMLWatchlist.cpp
        HTMLWatchlist.h
        FileWatchlist.cpp
        FileWatchlist.h
        TutorialValidator.cpp
        TutorialValidator.h
        Utils.cpp
        Utils.h
        mainwindow.cpp
        mainwindow.h
        Filter.cpp
        Filter.h
        main.cpp
        Repo.cpp
        Repo.h
        Tutorial.cpp
        Tutorial.h
        UI.cpp
        UI.h
        Watchlist.cpp
        Watchlist.h)