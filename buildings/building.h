//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_BUILDING_H
#define HMM4_BUILDING_H

#include "../units/Unit.h"

class Building{
public:
    ~Building()= default;
    virtual std::string Name() const = 0;
    virtual std::string Description() const = 0;
};

class Hall : public Building {
public:
    ~Hall()= default;
    std::string Name() const override {
        return "Hall";
    }
    std::string Description() const override {
        return "Hall";
    }
};

class Fort : public Building {
public:
    ~Fort()= default;
    std::string Name() const override {
        return "Fort";
    }
    std::string Description() const override {
        return "Fort";
    }
};

class UnitBuilding : public Building {
public:
    int cost;
    Unit* unit;
    double number;
    ~UnitBuilding()= default;
    std::string Name() const override = 0;
    std::string Description() const override = 0;
    void Produce(){
        number += (unit->GetGrowth() / 7.0);
    }
    int GetNumber() const{
        return floor(number);
    }
    void Recruit(int n){
        number -= n;
    }
};

#endif //HMM4_BUILDING_H
