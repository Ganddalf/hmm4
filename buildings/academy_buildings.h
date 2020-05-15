//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_ACADEMY_BUILDINGS_H
#define HMM4_ACADEMY_BUILDINGS_H
#include <string>

#include "building.h"
#include "../units/Unit.h"
#include "../units/academy_units.h"

class DwarvenMines : public UnitBuilding {
public:
    DwarvenMines(){
        this->unit = new Dwarf();
    }
    ~DwarvenMines(){}
    std::string Description() const override {
        return "Dwarven Mines";
    }
};

class HalflingBurrows : public UnitBuilding {
public:
    HalflingBurrows(){}
    ~HalflingBurrows(){}
    std::string Description() const override {
        return "Halfling Burrows";
    }
    Unit* GetUnit(){
        Halfling* halfling = new Halfling();
        return halfling;
    }
};

class GolemFactory : public UnitBuilding {
public:
    GolemFactory(){}
    ~GolemFactory(){}
    std::string Description() const override {
        return "Golem Factory";
    }
    Unit* GetUnit(){
        GoldGolem* goldGolem = new GoldGolem();
        return goldGolem;
    }
};

class GoldenPavilion : public UnitBuilding {
public:
    GoldenPavilion(){}
    ~GoldenPavilion(){}
    std::string Description() const override {
        return "Golden Pavilion";
    }
    Unit* GetUnit(){
        Naga* naga = new Naga();
        return naga;
    }
};

class CloudCastle : public UnitBuilding {
public:
    CloudCastle(){}
    ~CloudCastle(){}
    std::string Description() const override {
        return "Cloud Castle";
    }
    Unit* GetUnit(){
        Titan* titan = new Titan();
        return titan;
    }
};

#endif //HMM4_ACADEMY_BUILDINGS_H
