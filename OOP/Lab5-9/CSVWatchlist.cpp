//
//  CSVWatchlist.cpp
//  Lab5-6STL
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//
#include "CSVWatchlist.h"
#include <fstream>
#include "RepositoryExceptions.h"

using namespace std;

void CSVWatchlist::writeToFile()
{
    ofstream f(this->filename);
    
    if (!f.is_open())
        throw FileException("The file could not be opened!");
    
    for (auto s : this->TutorialInWatch)
        f << s;
    
    f.close();
}

void CSVWatchlist::readFromFile()
{
    ifstream file(this->filename);

    if (!file.is_open())
        throw FileException("The file could not be opened!");

    Tutorial s;
    while (file >> s)
        this->TutorialInWatch.push_back(s);

    file.close();
}

void CSVWatchlist::displayWatchlist() const
{
    string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
    string link = "open -a Numbers " + aux;
    system(link.c_str());
}
