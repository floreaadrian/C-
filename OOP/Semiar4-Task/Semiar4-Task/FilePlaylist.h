//
//  FilePlaylist.h
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include "PlayList.h"

class FilePlaylist : public PlayList
{
protected:
    std::string filename;
    
public:
    FilePlaylist(const std::string& filename);
    virtual ~FilePlaylist() {}
    
    virtual void writeToFile() = 0;
   // virtual void displayPlaylist() const = 0;
};

