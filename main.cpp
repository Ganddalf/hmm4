#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cmath>
#include <cstdlib>

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

    void ProduceUnitBuilding1()const override {
        HalflingBurrows* unitBuilding = new HalflingBurrows();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding2()const override {
        DwarvenMines* unitBuilding = new DwarvenMines();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding3()const override {
        GolemFactory* unitBuilding = new GolemFactory();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding4()const override {
        GoldenPavilion* unitBuilding = new GoldenPavilion();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding5()const override {
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
        this->builder->ProduceUnitBuilding1();
    }

    void BuildMediumTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding1();
        this->builder->ProduceUnitBuilding2();
        this->builder->ProduceUnitBuilding3();
    }
    void BuildLargeTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProduceTavern();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding1();
        this->builder->ProduceUnitBuilding2();
        this->builder->ProduceUnitBuilding3();
        this->builder->ProduceUnitBuilding4();
        this->builder->ProduceUnitBuilding5();

    }
};

class Squad{
protected:
    Unit* unit;
    int number;
public:
    Squad(){
        unit = NULL;
        number = 0;
    }
    Squad(Unit* unit, unsigned int number){
        this->unit = unit;
        this->number = number;
    }
    ~Squad(){}
    string HowMuch(){
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
    string GetUnitName(){
        return unit->name();
    }

    int GetNumber(){
        return number;
    }

    int GetDied(int dmg){
        int hp = unit->GetHP();
        int died = dmg/hp;
        if (died > number){
            died = number;
        }
        return died;
    }

    int GetDamage(){
        return number * unit->GetDamage();
    }

    void Dismiss(){
        unit = NULL;
        number = 0;
    }

    void AddUnits(int n) {
        number += n;
    }

};

class Army{
public:
    vector< Squad* > squads;
    int max_size;

    Army(){
        max_size = 7;
    }

    ~Army(){};

    string AddSquad(Squad* squad){
        for(int i = 0; i < squads.size(); i++){
            string name = squad->GetUnitName();
            int number = squad->GetNumber();
            if(squads[i]->GetUnitName() == name){
                squads[i]->AddUnits(number);
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

    void Show(){
        cout << "\nВаша армия: \n";
        for(int i = 0; i < squads.size(); i++){
            cout << squads[i]->GetUnitName() << "\t" << squads[i]->GetNumber() << '\n';
        }
    }
    void ShowEnemy(){
        cout << "\nСведения о вражеской армии: \n";
        for(int i = 0; i < squads.size(); i++){
            cout << squads[i]->GetUnitName() << "\t" << squads[i]->HowMuch() << '\n';
        }
    }

    void Dismiss(int n){
        squads[n]->Dismiss();
        squads.erase(squads.begin() + n);
    }

};

int main(){
    system("chcp 65001");

//    Director* director= new Director();
//    AcademyBuilder* builder = new AcademyBuilder();
//    director->set_builder(builder);
//    int N;
//    cout << "Select: little(1), medium(2) or large(3) town: ";
//    cin >> N;
//
//    Town* town;
//
//    if(N == 1){
//        cout << "Little town\n";
//        director->BuildLittleTown();
//    } else if(N == 2){
//        cout << "Medium town\n";
//        director->BuildMediumTown();
//    } else if(N == 3){
//        cout << "Large town\n";
//        director->BuildLargeTown();
//    } else {
//        delete director;
//        delete builder;
//        return 0;
//    }
//    town = builder->GetTown();
//    delete builder;
//    delete director;
//
//    town->ListBuildings();
//
//    town->AvailableUnitBuildings();
//
//    delete town;

    Squad squad1(new Halfling, 204);
    Squad squad2(new Dwarf, 178);
    Squad squad3(new GoldGolem,58);
    Squad squad4(new Naga, 23);
    Squad squad5(new Titan, 7);

    Squad squad6(new Naga, 85);

    Army army1;
    army1.Show();
    army1.AddSquad(&squad1);
    army1.AddSquad(&squad2);
    army1.Show();
    army1.AddSquad(&squad3);
    army1.AddSquad(&squad4);
    army1.Show();

    army1.ShowEnemy();

    army1.AddSquad(&squad6);
    army1.AddSquad(&squad5);
    army1.Show();

    return 0;
}