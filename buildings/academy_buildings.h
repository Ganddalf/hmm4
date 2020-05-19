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
        number = 6;
        cost = 1500;
        unit = new Dwarf();
    }
    ~DwarvenMines()= default;
    std::string Description() const override {
        return "Рудники гномов: позволяет нанимать гномов";
    }
    std::string Name() const override {
        return "Рудники гномов";
    }
};

class HalflingBurrows : public UnitBuilding {
public:
    HalflingBurrows(){
        number = 6;
        cost = 1500;
        unit = new Halfling();
    }
    ~HalflingBurrows()= default;
    std::string Description() const override {
        return "Норы полуросликов: позволяет нанимать полуросликов";
    }
    std::string Name() const override {
        return "Норы полуросликов";
    }
};

class GolemFactory : public UnitBuilding {
public:
    GolemFactory(){
        number = 3;
        cost = 3500;
        unit = new GoldGolem();
    }
    ~GolemFactory()= default;
    std::string Description() const override {
        return "Фабрика големов: позволяет нанимать золотых големов";
    }
    std::string Name() const override {
        return "Фабрика големов";
    }
};

class GoldenPavilion : public UnitBuilding {
public:
    GoldenPavilion(){
        number = 2;
        cost = 7000;
        unit = new Naga();
    }
    ~GoldenPavilion()= default;
    std::string Description() const override {
        return "Золотой павильон: позволяет нанимать Наг";
    }
    std::string Name() const override {
        return "Золотой павильон";
    }
};

class CloudCastle : public UnitBuilding {
public:
    CloudCastle(){
        number = 1;
        cost = 14000;
        unit = new Titan();
    }
    ~CloudCastle()= default;
    std::string Description() const override {
        return "Облачный замок: позволяет нанимать титанов";
    }
    std::string Name() const override {
        return "Облачный замок";
    }
};

#endif //HMM4_ACADEMY_BUILDINGS_H
