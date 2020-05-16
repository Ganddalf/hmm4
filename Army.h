//
// Created by potap on 16.05.2020.
//

#ifndef HMM4_ARMY_H
#define HMM4_ARMY_H

#include <iostream>
#include <vector>

#include "Squad.h"

using namespace std;

class Army{
public:
    vector< Squad* > squads;
    int max_size;

    Army();
    ~Army()= default;

    string AddSquad(Squad* squad);
    void Show();
    void ShowEnemy();
    void Dismiss(int n);
};


#endif //HMM4_ARMY_H
