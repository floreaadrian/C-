//
//  HTMLWatchlist.h
//  Lab5-6STL
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#pragma once
#include "FileWatchlist.h"
#include <string>

class HTMLWatchlist: public FileWatchlist
{
public:
    HTMLWatchlist(const std::string& filename) : FileWatchlist{ filename } {readFromFile();}
    
    /*
     Read the playlist to file.
     Throws: FileException - if it cannot read.
     */
    void readFromFile() override;
    /*
     Writes the playlist to file.
     Throws: FileException - if it cannot write.
     */
    void writeToFile() override;
    
    /*
     Displays the playlist using Microsof Excel.
     */
    void displayWatchlist() const override;
};

