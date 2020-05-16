//
// Created by potap on 16.05.2020.
//

#ifndef HMM4_SQUAD_H
#define HMM4_SQUAD_H

#include <string>

#include "units/Unit.h"

using namespace std;

class Squad{
protected:
    Unit* unit;
    int number;
public:
    Squad();
    Squad(Unit* unit, int number);
    ~Squad()= default;

    string HowMuch() const;
    string GetUnitName();
    int GetNumber() const;
    int GetDied(int dmg);
    int GetDamage();
    void Dismiss();
    void AddUnits(int n);
};


#endif //HMM4_SQUAD_H
