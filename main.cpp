#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cmath>
#include <cstdlib>

#include "Town_Builder.h"
#include "units/Unit.h"
#include "units/academy_units.h"
#include "Squad.h"
#include "Army.h"

using namespace std;

int main(){
    system("chcp 65001");

    auto* director= new Director();
    auto* builder = new AcademyBuilder();
    director->set_builder(builder);

    Town* town;

    director->BuildLittleTown();
    town = builder->GetTown();

    delete builder;
    delete director;

    town->ListBuildings();

    town->AvailableUnitBuildings();

    delete town;

    return 0;
}