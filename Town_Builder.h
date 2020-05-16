//
// Created by potap on 16.05.2020.
//

#ifndef HMM4_TOWN_BUILDER_H
#define HMM4_TOWN_BUILDER_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "buildings/building.h"
#include "buildings/academy_buildings.h"

using namespace std;

class Town{
public:
    std::string name;
    std::vector<Building*> buildings_;
    std::vector<UnitBuilding*> unit_buildings;
    int state;
    bool wasBuildedToday;

    Town();
    explicit Town(std::string name);

    void ListBuildings()const;
    void AvailableUnitBuildings()const;
    string GetInfoForNextBuilding();
};


class TownBuilder{
public:
    virtual ~TownBuilder()= default;
    virtual void ProduceHall() const =0;
    virtual void ProduceFort() const =0;
    virtual void BuildUnitPrototypes() const = 0;
    virtual void ProduceUnitBuilding1() const =0;
    virtual void ProduceUnitBuilding2() const =0;
    virtual void ProduceUnitBuilding3() const =0;
    virtual void ProduceUnitBuilding4() const =0;
    virtual void ProduceUnitBuilding5() const =0;
};


class AcademyBuilder : public TownBuilder{
private:
    Town* town;
public:

    AcademyBuilder();

    ~AcademyBuilder() override;

    void Reset();


    void ProduceHall()const override;

    void ProduceFort()const override;

    void BuildUnitPrototypes()const override;

    void ProduceUnitBuilding1()const override;
    void ProduceUnitBuilding2()const override;
    void ProduceUnitBuilding3()const override;
    void ProduceUnitBuilding4()const override;
    void ProduceUnitBuilding5()const override;

    Town* GetTown();
};


class Director{
private:
    TownBuilder* builder;
public:

    void set_builder(TownBuilder* builder_);

    void BuildLittleTown();
};


#endif //HMM4_TOWN_BUILDER_H
