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
    DwarvenMines(){}
    ~DwarvenMines(){}
    std::string Description() const override {
        return "Dwarven Mines";
    }
    Unit* GetUnit(){
        Dwarf* dwarf = new Dwarf();
        return dwarf;
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

class MageTower : public UnitBuilding {
public:
    MageTower(){}
    ~MageTower(){}
    std::string Description() const override {
        return "Mage Tower";
    }
    Unit* GetUnit(){
        Mage* mage = new Mage();
        return mage;
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

class AltarOfWishes : public UnitBuilding {
public:
    AltarOfWishes(){}
    ~AltarOfWishes(){}
    std::string Description() const override {
        return "Altar of Wishes";
    }
    Unit* GetUnit(){
        Genie* genie = new Genie();
        return genie;
    }
};

class DragonFactory : public UnitBuilding {
public:
    DragonFactory(){}
    ~DragonFactory(){}
    std::string Description() const override {
        return "Dragon Factory";
    }
    Unit* GetUnit(){
        DragonGolem* dragonGolem = new DragonGolem();
        return dragonGolem;
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
