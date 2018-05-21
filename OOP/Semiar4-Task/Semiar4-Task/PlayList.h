//
//  PlayList.hpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include <vector>
#include "Song.h"

class PlayList
{
protected:
    std::vector<Song> songs;
    int current;
    
public:
    PlayList();
    
    // Adds a song to the playlist.
    void add(const Song& song);
    
    // Returns the song that is currently playing.
    Song getCurrentSong();
    
    // Starts the playlist - plays the first song.
    void play();
    
    // Plays the next song in the playlist.
    void next();
    
    // Checks if the playlist is empty.
    bool isEmpty();
    
    virtual ~PlayList() {}
};


