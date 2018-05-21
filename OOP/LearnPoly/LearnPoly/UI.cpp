//
//  UI.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::run(){
    while (true) {
        cout<<"Hi\n";
        int command{0};
        string date;
        cout<<"Date(in the form yyyy.mm.dd): ";
        cin>>date;
        Medical* med = nullptr;
        cout<<"1.BMI\n2.BP\ncommand>> ";
        int choose;
        cin>>choose;
        if(choose==1){
            double val;
            cout<<"BMI value: ";
            cin>>val;
            med = new BMI(date,val);
        }else{
            int st,dy;
            cout<<"Systolic value : ";
            cin>>st;
            cout<<"Diastolic value: ";
            cin>>dy;
            med = new BP(date,st,dy);
        }
        this->ctrl.add(med);
        Medical* m = nullptr;
        m = new BMI(date,32);
        this->ctrl.add(m);
        for(auto it: this->ctrl.getAll())
            cout<<it->toString();
        //cout<<med->toString();
        this->ctrl.writeToFile();
        if(command == 0)
            break;
    }
}
