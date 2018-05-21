//
//  Repository.cpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Repository.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& filename)
{
    this->filename = filename;
    this->readFromFile();
}

void Repository::addSong(const Song& s)
{
    if (this->findByArtistAndTitle(s.getArtist(), s.getTitle()).getArtist() != "")
        throw DuplicateSongException();
    this->songs.push_back(s);
    this->writeToFile();
}

Song Repository::findByArtistAndTitle(const std::string& artist, const std::string& title) const
{
    for (auto s: this->songs)
    {
        if (s.getArtist() == artist && s.getTitle() == title)
            return s;
    }
    
    return Song{};
}

void Repository::readFromFile()
{
    ifstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    
    Song s;
    while (file >> s)
        this->songs.push_back(s);
    
    file.close();
}

void Repository::writeToFile()
{
    ofstream file(this->filename);
    
    cout<<file.is_open();
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    std::string link = "open -a Safari " + this->filename;
    std::system(link.c_str());
    for (auto s : this->songs)
    {
        file << s;
        cout<<s;
    }
    
    file.close();
}
