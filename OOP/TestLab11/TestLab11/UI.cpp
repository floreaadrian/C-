//
//  UI.cpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include <iostream>
#include <string>

using namespace std;

void UI::printMenu(){
    cout<<"1.Add a new painting.\n";
    cout<<"2.Move a painting from the gallarey to special storage\n";
    cout<<"3.Show gallery and special storage.\n";
    cout<<"4.Undo.\n";
    cout<<"0.Exit.\n";
}

void UI::addUi(){
    string name;
    cout<<"Name of the artist: ";
    cin>>name;
    string title;
    cout<<"Title of the painting: ";
    cin>>title;
    int year;
    cout<<"Year of the painting: ";
    cin>>year;
    this->ctrl.addPainting(name,title,year);
}

void UI::movePainting(){
    string name;
    cout<<"Name of the artist: ";
    cin>>name;
    string title;
    cout<<"Title of the painting: ";
    cin>>title;
    int year;
    cout<<"Year of the painting: ";
    cin>>year;
    this->ctrl.move(name, title, year);
}

void UI::undo(){
    this->ctrl.undoIt();
}

void UI::showGallery(){
    vector<Painting> gal = this->ctrl.getAll();
    vector<Painting> spe = this->ctrl.getAllSpecialStorage();
    cout<<"--------Gallery--------\n";
    for(auto it: gal)
        cout<<it.getArtist()<<" "<<it.getTitle()<<" "<<it.getYear()<<"\n";
    cout<<"----Special Gallery----\n";
    for(auto it: spe)
        cout<<it.getArtist()<<" "<<it.getTitle()<<" "<<it.getYear()<<"\n";
    cout<<"-----------------------\n";
}

void UI::run(){
    while(true){
        this->printMenu();
        int command{0};
        cout<<"Command: ";
        cin>>command;
        switch (command) {
            case 1:
                this->addUi();
                break;
            case 2:
                this->movePainting();
                break;
            case 3:
                this->showGallery();
                break;
            case 4:
                this->undo();
                break;
        }
        if(command == 0)
            break;
    }
}
