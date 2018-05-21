//
//  FileWatchlist.h
//  Lab5-6STL
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include "Watchlist.h"

class FileWatchlist : public Watchlist
{
protected:
    std::string filename;
    
public:
    FileWatchlist(const std::string& filename);
    virtual ~FileWatchlist() {}
    
    virtual void readFromFile() = 0;
    virtual void writeToFile() = 0;
    virtual void displayWatchlist() const = 0;
};

