//
//  CSVPlayList.h
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include "FilePlaylist.h"
#include <string>

class CSVPlaylist: public FilePlaylist
{
public:
    CSVPlaylist(const std::string& filename) : FilePlaylist{ filename } {}
    
    /*
     Writes the playlist to file.
     Throws: FileException - if it cannot write.
     */
    void writeToFile() override;
    
    /*
     Displays the playlist using Microsof Excel.
     */
    //void displayPlaylist() const override;
};

