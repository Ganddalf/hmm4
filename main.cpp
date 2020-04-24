#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "units/Unit.h"
#include "units/asylum_units.h"
#include "units/academy_units.h"
#include "buildings/building.h"
#include "buildings/academy_buildings.h"

using namespace std;


class Town{
public:
    std::string name;
    std::vector<Building*> buildings_;
    Town(){
        name = "default";
    }
    Town(std::string name){
        this->name = name;
    }

    void ListBuildings()const{
        std::cout << "Town buildings: ";
        for (size_t i=0; i<buildings_.size(); i++){
            std::cout << buildings_[i]->Description() << ", ";
        }
        std::cout << "\n\n";
    }
    void AvailableUnitBuildings()const{
        std::cout << "Available unit buildings: ";
        for (size_t i=0; i<buildings_.size(); i++){
            UnitBuilding* unitBuilding = dynamic_cast<UnitBuilding*>(buildings_[i]);
            if(unitBuilding){
                cout << unitBuilding->Description() << ", ";
            }
        }
        std::cout << "\n\n";
    }
};


class TownBuilder{
public:
    virtual ~TownBuilder(){}
    virtual void ProduceHall() const =0;
    virtual void ProduceFort() const =0;
    virtual void ProduceTavern() const =0;
    virtual void ProducePrison() const =0;
    virtual void ProduceUnitBuilding11() const =0;
    virtual void ProduceUnitBuilding12() const =0;
    virtual void ProduceUnitBuilding21() const =0;
    virtual void ProduceUnitBuilding22() const =0;
    virtual void ProduceUnitBuilding31() const =0;
    virtual void ProduceUnitBuilding32() const =0;
    virtual void ProduceUnitBuilding41() const =0;
    virtual void ProduceUnitBuilding42() const =0;
};


class AcademyBuilder : public TownBuilder{
private:
    Town* town;
public:

    AcademyBuilder(){
        this->Reset();
    }

    ~AcademyBuilder(){
        delete town;
    }

    void Reset(){
        this->town = new Town("Academy");
    }


    void ProduceHall()const override {
        Hall* hall = new Hall();
        this->town->buildings_.push_back(hall);
    }

    void ProduceFort()const override {
        Fort* fort = new Fort();
        this->town->buildings_.push_back(fort);
    }

    void ProduceTavern()const override {
        Tavern* tavern = new Tavern();
        this->town->buildings_.push_back(tavern);
    }

    void ProducePrison()const override {
        Prison* prison = new Prison();
        this->town->buildings_.push_back(prison);
    }

    void ProduceUnitBuilding11()const override {
        HalflingBurrows* unitBuilding = new HalflingBurrows();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding12()const override {
        DwarvenMines* unitBuilding = new DwarvenMines();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding21()const override {
        GolemFactory* unitBuilding = new GolemFactory();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding22()const override {
        MageTower* unitBuilding = new MageTower();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding31()const override {
        GoldenPavilion* unitBuilding = new GoldenPavilion();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding32()const override {
        AltarOfWishes* unitBuilding = new AltarOfWishes();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding41()const override {
        DragonFactory* unitBuilding = new DragonFactory();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding42()const override {
        CloudCastle* unitBuilding = new CloudCastle();
        this->town->buildings_.push_back(unitBuilding);
    }

    Town* GetTown() {
        Town* result= this->town;
        this->Reset();
        return result;
    }
};


class Director{
private:
    TownBuilder* builder;
public:

    void set_builder(TownBuilder* builder){
        this->builder=builder;
    }

    void BuildLittleTown(){
        this->builder->ProduceHall();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
    }

    void BuildMediumTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
        this->builder->ProduceUnitBuilding22();
    }
    void BuildLargeTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProduceTavern();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
        this->builder->ProduceUnitBuilding22();
        this->builder->ProduceUnitBuilding31();
        this->builder->ProduceUnitBuilding42();
    }
};


int main(){
    Director* director= new Director();
    AcademyBuilder* builder = new AcademyBuilder();
    director->set_builder(builder);
    int N;
    cout << "Select: little(1), medium(2) or large(3) town: ";
    cin >> N;

    Town* town;

    if(N == 1){
        cout << "Little town\n";
        director->BuildLittleTown();
    } else if(N == 2){
        cout << "Medium town\n";
        director->BuildMediumTown();
    } else if(N == 3){
        cout << "Large town\n";
        director->BuildLargeTown();
    } else {
        delete director;
        delete builder;
        return 0;
    }
    town = builder->GetTown();
    delete builder;
    delete director;

    town->ListBuildings();

    town->AvailableUnitBuildings();

    delete town;
    return 0;
}