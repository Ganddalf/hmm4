//
// Created by potap on 16.05.2020.
//

#include "Town_Builder.h"


Town::Town(){
    name = "default";
    state = 1;
    wasBuildedToday = false;
}

Town::Town(std::string name){
    this->name = std::move(name);
    state = 1;
    wasBuildedToday = false;
}

void Town::ListBuildings()const{
    std::cout << "Town buildings: ";
    for (auto building : buildings_){
        std::cout << building->Name() << ", ";
    }
    std::cout << "\n\n";
}

vector<UnitBuilding*> Town::AvailableUnitBuildings(){
    vector<UnitBuilding* > v;
    for (auto building : buildings_){
        auto* unitBuilding = dynamic_cast<UnitBuilding*>(building);
        if(unitBuilding){
            v.push_back(unitBuilding);
        }
    }
    return v;
}

string Town::GetInfoForNextBuilding(){
    if(state == 5){
        return "Вы построили все здания в этом городе!";
    } else {
        return unit_buildings[state]->Description();
    }
}

string Town::BuildNextBuilding(){
    if(state == 5){
        return "Вы построили все здания в этом городе!";
    } else {
        buildings_.push_back(unit_buildings[state]);
        state++;
        return "Построено здание: " + unit_buildings[state - 1]->Name();
    }
}

AcademyBuilder::AcademyBuilder(){
    town = nullptr;
    this->Reset();
}

AcademyBuilder::~AcademyBuilder(){
    delete town;
}

void AcademyBuilder::Reset(){
    this->town = new Town("Academy");
}


void AcademyBuilder::ProduceHall()const {
    Hall* hall = new Hall();
    this->town->buildings_.push_back(hall);
}

void AcademyBuilder::ProduceFort()const {
    Fort* fort = new Fort();
    this->town->buildings_.push_back(fort);
}

void AcademyBuilder::BuildUnitPrototypes()const {
    this->town->unit_buildings.push_back(new HalflingBurrows());
    this->town->unit_buildings.push_back(new DwarvenMines());
    this->town->unit_buildings.push_back(new GolemFactory());
    this->town->unit_buildings.push_back(new GoldenPavilion());
    this->town->unit_buildings.push_back(new CloudCastle());
}

void AcademyBuilder::ProduceUnitBuilding1()const {
    auto* unitBuilding = this->town->unit_buildings[0];
    this->town->buildings_.push_back(unitBuilding);
    this->town->state = 1;
}

void AcademyBuilder::ProduceUnitBuilding2()const {
    auto* unitBuilding = this->town->unit_buildings[1];
    this->town->buildings_.push_back(unitBuilding);
    this->town->state = 2;
}

void AcademyBuilder::ProduceUnitBuilding3()const {
    auto* unitBuilding = this->town->unit_buildings[2];
    this->town->buildings_.push_back(unitBuilding);
    this->town->state = 3;
}

void AcademyBuilder::ProduceUnitBuilding4()const {
    auto* unitBuilding = this->town->unit_buildings[3];
    this->town->buildings_.push_back(unitBuilding);
    this->town->state = 4;
}

void AcademyBuilder::ProduceUnitBuilding5()const {
    auto* unitBuilding = this->town->unit_buildings[4];
    this->town->buildings_.push_back(unitBuilding);
    this->town->state = 5;
}

Town* AcademyBuilder::GetTown() {
    Town* result= this->town;
    this->Reset();
    return result;
}

void Director::set_builder(TownBuilder* builder_){
    this->builder = builder_;
}

void Director::BuildLittleTown(){
    this->builder->ProduceHall();
    this->builder->BuildUnitPrototypes();
    this->builder->ProduceUnitBuilding1();
}

