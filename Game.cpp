//
// Created by potap on 16.05.2020.
//

#include "Game.h"

#include <utility>

Game::Game() {
    date = 0;
    currentTown = 0;
    gold = 2000;

    cout << "Введите название города:  ";
    string name;
    cin >> name;

    myTowns.push_back(CreateTown(name));

    for(int i = 0; i < 10; i++){
        Turn();
        EndTurn();
    }
}

void Game::Turn() {
    Town* town = myTowns[currentTown];
    bool b = true;
    do {
        ShowTownDateGold();
        PrintMenu();
        int choose;
        cin >> choose;
        system("cls");
        if (choose == 1) {
            cout << "Название города: " << town->name << endl;
            cout << "Тип города: " << town->type << endl;
            cout << "Здания в городе: " << endl;
            for(auto & building : town->buildings_) {
                cout << "---- " << building->Description() << endl;
            }
        } else if (choose == 2) {
            BuildMenu(town);
        } else if (choose == 3) {
            RecruitsMenu(town);
        } else if (choose == 4) {
            return;
        } else if (choose == 5) {
            return;
        } else if (choose == 6) {
            return;
        } else if (choose == 7) {
            return;
        } else if (choose == 0) {
            return;
        } else {
            cout << "Неизвестная опция, повторите ввод";
        }
        cout <<"\n\n Нажмите любую клавишу\n";
        getchar();
        getchar();
        system("cls");
    } while(b);
}

void Game::PrintMenu(){
    cout << "---- 1) Информация о текущем городе\n"
         << "---- 2) Построить здание\n"
         << "---- 3) Нанять юнитов\n"
         << "---- 4) Ваша армия\n"
         << "---- 5) Посмотреть на карту\n"
         << "---- 6) Переместиться в другой город\n"
         << "---- 7) Атаковать другой город или армию\n\n"
         << "---- 0) Закончить ход\n";
}

void Game::EndTurn() {
    for(auto & myTown : myTowns){
        myTown->wasBuildedToday = false;
        auto unitBuildings = myTown->AvailableUnitBuildings();
        for(auto & unitBuilding : unitBuildings){
            unitBuilding->Produce();
        }
    }
    gold += myTowns.size() * 1000;
    date++;
}

string Game::GetDate() const {
    int week = date / 7;
    int month = week / 4;
    week %= 4;
    int day = date % 7;
    day++;
    week++;
    month++;
    return "День " + to_string(day) + ", недели " + to_string(week) + ", месяца " + to_string(month) + ".";
}

Town* Game::CreateTown(string name) {
    auto* director= new Director();
    auto* builder = new AcademyBuilder();
    director->set_builder(builder);

    Town* town;

    director->BuildLittleTown();
    town = builder->GetTown();
    town->type = "Академия";
    town->name = name;

    delete builder;
    delete director;
    return town;
}

void Game::ShowTownDateGold() {
    cout << "\n\nТекущий город: " << myTowns[currentTown]->type << ' ' << myTowns[currentTown]->name << ".\n";
    cout << GetDate() << " Золото: " << gold << endl;
}

void Game::BuildMenu(Town* town) const {
    if (town->wasBuildedToday){
        cout << "Вы строили уже сегодня в этом городе!\n";
    } else if(town->state == 5){
        cout << "Вы построили все здания в этом городе!\n";
    } else {
        int cost = town->unit_buildings[ town->state ]->cost;
        cout << town->GetInfoForNextBuilding() << ". Стоимость: " << cost << endl;

        if(gold < cost){
            cout << "У вас не хватает золота!\n";
        } else {
            cout << "Построить это здание? (Да - 1, Нет - 0)" << endl;
            int check;
            cin >> check;
            if(check){
                cout << town->BuildNextBuilding() << endl;
                town->wasBuildedToday = true;
            }
        }
    }
}

void Game::RecruitsMenu(Town *town) {
    cout << "Доступные для найма рекруты: \n";
    auto unitBuildings = town->AvailableUnitBuildings();
    for(int i = 0; i < unitBuildings.size(); i++){
        cout << "---- " << i + 1 << ") " << unitBuildings[i]->unit->name() << ", " << unitBuildings[i]->GetNumber() << endl;
    }
}