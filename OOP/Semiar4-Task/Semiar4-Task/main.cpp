//
//  main.cpp
//  Semiar4-Task
//
//  Created by Adrian-Paul Florea on 4/23/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include "RepositoryExceptions.h"
#include "CSVPlayList.h"
using namespace std;

int main()
{
    
    try
    {
        Repository repo("Songs.txt");
        FilePlaylist* p = nullptr;
        cout << "What type of file wuld you like to use to store the playlist (CSV/JSON)?";
        string fileType{};
        cin >> fileType;
        if (fileType == "JSON")
           // p = new JSONPlayList{ "playlist.json" };
            cout<<"Hei";
        else
            p = new CSVPlaylist{ "playlist.csv" };
        Controller ctrl(repo, p, SongValidator{});
        UI ui(ctrl);
        ui.run();
        delete p;
    }
    catch (FileException&)
    {
        cout << "Repository file could not be opened! The application will terminate." << endl;
        return 1;
    }
    
    return 0;
}
