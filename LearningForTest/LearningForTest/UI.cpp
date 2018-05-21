//
//  UI.cpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include <iostream>
#include <vector>

void UI::printMenu(){
    std::cout<<"1.Add an object\n";
    std::cout<<"2.Delete an object by id\n";
    std::cout<<"3.Update an object\n";
    std::cout<<"4.Print all\n";
    std::cout<<"0.Exit\n";
}

void UI::add(){
    int age;
    std::cout<<"Age: ";
    std::cin>>age;
    std::string name;
    std::cout<<"Name: ";
    std::cin>>name;
    //getline(std::cin,name);
    //std::cin.ignore();
    int id;
    std::cout<<"Id: ";
    std::cin>>id;
    //std::cin.ignore();
    int res= this->ctrl.add(age,name,id);
    if(res==1)
        std::cout<<"Succsesfull add\n";
    else
        std::cout<<"Unsuccsesfull add\n";
}

void UI::deleteObj(){
    int id;
    std::cout<<"The id of the object you want to remove: ";
    std::cin>>id;
    int res=this->ctrl.deleteObj(id);
    if(res==1)
        std::cout<<"Succsesfull delete\n";
    else
        std::cout<<"Unsuccsesfull delete\n";
}

void UI::update(){
    int id;
    std::cout<<"The id of the object you want to update: ";
    std::cin>>id;
    int age;
    std::cout<<"New age: ";
    std::cin>>age;
    std::string name;
    std::cout<<"New name: ";
    std::cin>>name;
    int res=this->ctrl.update(id, age, name);
    if(res==1)
        std::cout<<"Succsesfull update\n";
    else
        std::cout<<"Unsuccsesfull update\n";
}

void UI::printObj(){
    std::vector <Domain> toPrint=this->ctrl.getRepo().getData();
    for(int i=0;i<40;++i)
        std::cout<<"-";
    std::cout<<"\n";
    for(auto it: toPrint){
        std::cout<<"Name: "<<it.getName()<<"\n";
        std::cout<<"Age: "<<it.getAge()<<"\n";
        std::cout<<"Id: "<<it.getId()<<"\n";
        for(int i=0;i<40;++i)
            std::cout<<"-";
        std::cout<<"\n";
    }
}

void UI::sortObj(){
    std::vector<Domain> toPrint=this->ctrl.getRepo().getVectorSorted();
    for(int i=0;i<40;++i)
        std::cout<<"-";
    std::cout<<"\n";
    for(auto it: toPrint){
        std::cout<<"Name: "<<it.getName()<<"\n";
        std::cout<<"Age: "<<it.getAge()<<"\n";
        std::cout<<"Id: "<<it.getId()<<"\n";
        for(int i=0;i<40;++i)
            std::cout<<"-";
        std::cout<<"\n";
    }
}

void UI::run(){
    this->printMenu();
    while(true){
        std::cout<<"Command: ";
        int cmd;
        std::cin>>cmd;
        if(cmd==0)
            break;
        switch (cmd) {
            case 1:
                this->add();
                break;
            case 2:
                this->deleteObj();
                break;
            case 3:
                this->update();
                break;
            case 4:
                this->printObj();
                break;
            case 5:
                this->sortObj();
                break;
        }
        
    }
}
