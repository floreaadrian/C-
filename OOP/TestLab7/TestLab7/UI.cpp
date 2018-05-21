//
//  UI.cpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include <iostream>
#include <string>

void UI::printMenu(){
    std::cout<<"1 - Add a team\n";
    std::cout<<"2 - List teams sorted\n";
    std::cout<<"3 - Pair teams\n";
    std::cout<<"0 - Exit\n";
}

void UI::addFunc(){
    std::string name;
    std::cout<<"The name of the team: ";
    std::cin>>name;
    std::cout<<"The name of the country: ";
    std::string country;
    std::cin>>country;
    int res = this->ctrl.addCtrl(name, country);
    if(res==1)
        std::cout<<"Add was succsesful\n";
    else
        std::cout<<"Unsuccsesfull add\n";
}


void UI::printSorted(){
    std::vector<Teams> toPrint = this->ctrl.getSorted();
    for(auto it: toPrint)
        std::cout<<it.getName()<<" | "<<it.getCountry()<<" | "<<it.getScore()<<"\n";

}

void UI::pairTeams(){
    std::string team1;
    std::cout<<"First team: ";
    std::cin>>team1;
    std::string team2;
    std::cout<<"Second team: ";
    std::cin>>team2;
    std::string winning;
    std::cout<<"Winning team: ";
    std::cin>>winning;
    int res=this->ctrl.pairTeams(team1,team2,winning);
    if(res==1)
        std::cout<<"Pair was succsesful\n";
    else
        std::cout<<"Unsuccsesfull pair\n";
}

void UI::start(){
    int command;
    this->printMenu();
    std::cout<<"Command: ";
    std::cin>>command;
    while(command != 0){
        switch (command) {
            case 1:
                this->addFunc();
                break;
            case 2:
                this->printSorted();
                break;
            case 3:
                this->pairTeams();
        }
        std::cout<<"Command: ";
        std::cin>>command;
    }
}
