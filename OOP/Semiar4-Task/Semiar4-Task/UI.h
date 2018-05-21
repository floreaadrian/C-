//
//  UI.hpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//
#pragma once
#include "Controller.h"

class UI
{
private:
    Controller ctrl;
    
public:
    UI(const Controller& c) : ctrl(c) {}
    
    void run();
    
private:
    static void printMenu();
    static void printRepositoryMenu();
    static void printPlayListMenu();
    
    void addSongToRepo();
    void displayAllSongsRepo();
    void addSongToPlaylist();
    void addAllSongsByArtistToPlaylist();
    void savePlaylistToFile();
};

