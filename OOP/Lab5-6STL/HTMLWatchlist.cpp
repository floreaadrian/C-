//
//  HTMLWatchlist.cpp
//  Lab5-6STL
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//
#include "HTMLWatchlist.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "RepositoryExceptions.h"

using namespace std;

void HTMLWatchlist::writeToFile()
{
    ofstream f(this->filename);

    if (!f.is_open())
        throw FileException("The file could not be opened!");

    f << "<!DOCTYPE html>\n";
    f << "<html>\n";
    f << "<head>\n";
    f << "<title>Playlist</title>\n";
    f << "</head>\n";
    f << "<body>\n";
    f << "<table border="
      << "\""
      << "1"
      << "\""
      << ">\n";
    f << "<tr>\n";
    f << "<td>Presenter</td>\n";
    f << "<td>Title</td>\n";
    f << "<td>Duration</td>\n";
    f << "<td>Likes</td>\n";
    f << "<td>Link</td>\n";
    f << "</tr>\n";
    for (auto s : this->TutorialInWatch)
    {
        f << "<tr>\n";
        f << "<td>" << s.getPresenter() << "</td>\n";
        f << "<td>" << s.getTitle() << "</td>\n";
        f << "<td>" << s.getDuration().getMinutes() << ":" << s.getDuration().getSeconds() << "</td>\n";
        f << "<td>" << s.getLikes() << "</td>\n";
        f << "<td>\n<a href=\"" << s.getSource() << "\">Link</a>\n</td>\n";
        f << "</tr>\n";
    }
    f << "</table>\n";
    f << "</body>\n";
    f << "</html>\n";
    f.close();
}

string toModify(const string &s,const string &to,int newPos=4){
    string result(trim(s));
    result.erase(0, newPos);
    size_t pos = result.find_last_not_of(to);
    if (pos != std::string::npos)
        result.erase(pos + 1);
    if(to=="")
        result.erase(result.size()-10);
    //cout << result << "\n";
    return result;
}

void HTMLWatchlist::readFromFile()
{
    ifstream file(this->filename);

    if (!file.is_open())
        throw FileException("The file could not be opened!");
    string s;
    for (int i = 0; i < 14; ++i)
        getline(file, s);

    while (file >> s && s != "</table>")
    {
        string presenter, title, source, duration;
        double minutes, secundes;
        int likes;
        string toRead;
        getline(file, toRead);
        getline(file, toRead);
        presenter = toModify(toRead, "</td>");

        getline(file, toRead);
        title = toModify(toRead, "</td>");

        getline(file, toRead);
        duration = toModify(toRead, "</td>");
        vector<string> durationTokens = tokenize(duration, ':');
        minutes = stod(durationTokens[0]);
        secundes = stod(durationTokens[1]);

        getline(file, toRead);
        likes = stoi(toModify(toRead, "</td>"));
        getline(file,toRead);
        getline(file, toRead);
        source = toModify(toRead, "",9);
        getline(file,toRead);
        Tutorial tut{presenter, title, Duration{minutes, secundes}, likes, source};

        getline(file, toRead);
        this->TutorialInWatch.push_back(tut);
    }

    file.close();
}

void HTMLWatchlist::displayWatchlist() const
{
    string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
    string link = "open -a Safari " + aux;
    system(link.c_str());
}
