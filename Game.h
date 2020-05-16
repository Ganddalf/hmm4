//
// Created by potap on 16.05.2020.
//

#ifndef HMM4_GAME_H
#define HMM4_GAME_H

#include <iostream>
#include <vector>
#include <string>

#include "Town_Builder.h"


class Game {
private:
    int date;
    vector< Town* > myTowns;
    int currentTown;
    int gold;
public:
    Game();
    void Turn();
    void EndTurn();
    string GetDate() const;
    void ShowTownDateGold();
    void BuildMenu(Town* town) const;
    void RecruitsMenu(Town* town);
    static void PrintMenu();
    static Town* CreateTown(string name);
};


#endif //HMM4_GAME_H
