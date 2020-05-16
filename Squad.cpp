//
// Created by potap on 16.05.2020.
//

#include "Squad.h"

Squad::Squad(){
    unit = nullptr;
    number = 0;
}
Squad::Squad(Unit* unit, int number){
    this->unit = unit;
    this->number = number;
}

string Squad::HowMuch()const {
    if(number == 0){
        return " - ";
    } else if(number < 5){
        return "Несколько";
    } else if(number < 10){
        return "Немного";
    } else if(number < 20){
        return "Группа";
    } else if(number < 50){
        return "Много";
    } else if(number < 100){
        return "Орда";
    } else if(number < 200){
        return "Сотни";
    } else if(number < 500){
        return "Туча";
    } else if(number < 1000){
        return "Тьма";
    } else {
        return "Легион";
    }
}

string Squad::GetUnitName(){
    return unit->name();
}

int Squad::GetNumber() const{
    return number;
}

int Squad::GetDied(int dmg){
    int hp = unit->GetHP();
    int died = dmg/hp;
    if (died > number){
        died = number;
    }
    return died;
}

int Squad::GetDamage(){
    return number * unit->GetDamage();
}

void Squad::Dismiss(){
    unit = nullptr;
    number = 0;
}

void Squad::AddUnits(int n) {
    number += n;
}
