//
// Created by potap on 16.05.2020.
//

#include "Army.h"


Army::Army(){
    max_size = 7;
}

string Army::AddSquad(Squad* squad){
    for(auto & i : squads){
        string name = squad->GetUnitName();
        int number = squad->GetNumber();
        if(i->GetUnitName() == name){
            i->AddUnits(number);
            //delete squad;
            return "В вашу армию добавлены юниты: " + name + ", " + to_string(number);
        }
    }
    if(squads.size() < max_size){
        squads.push_back(squad);
        return "В вашу армию добавлены юниты: " + squad->GetUnitName() + ", " + to_string(squad->GetNumber());
    }
    return "В вашей армии нет места для " + squad->GetUnitName();
}

void Army::Show(){
    cout << "\nВаша армия: \n";
    for(auto & squad : squads){
        cout << squad->GetUnitName() << "\t" << squad->GetNumber() << '\n';
    }
}
void Army::ShowEnemy(){
    cout << "\nСведения о вражеской армии: \n";
    for(auto & squad : squads){
        cout << squad->GetUnitName() << "\t" << squad->HowMuch() << '\n';
    }
}

void Army::Dismiss(int n){
    squads[n]->Dismiss();
    squads.erase(squads.begin() + n);
}

