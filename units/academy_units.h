//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_ACADEMY_UNITS_H
#define HMM4_ACADEMY_UNITS_H

class Halfling : public Unit {
public:
    Halfling(){
        costPerUnit = 22;
        meleeAttack = 5;
        rangedAttack = 10;
        meleeDefense = 10;
        rangedDefense = 10;
        hitPoints = 8;
        damage = 1;
        movement = 18;
        speed = 6;
        ammo = 10;
        growth = 23;
    }
    ~Halfling(){}
    std::string Description() const override{
        return "Halfling";
    }
};

class Dwarf : public Unit {
public:
    Dwarf(){
        costPerUnit = 28;
        meleeAttack = 11;
        rangedAttack = 0;
        meleeDefense = 11;
        rangedDefense = 11;
        hitPoints = 12;
        damage = 2;
        movement = 18;
        speed = 3;
        ammo = 0;
        growth = 18;
    }
    ~Dwarf(){}
    std::string Description() const override{
        return "Dwarf";
    }
};

class GoldGolem : public Unit {
public:
    GoldGolem(){
        costPerUnit = 240;
        meleeAttack = 16;
        rangedAttack = 0;
        meleeDefense = 16;
        rangedDefense = 16;
        hitPoints = 50;
        damage = 8;
        movement = 19;
        speed = 3;
        ammo = 0;
        growth = 6;
    }
    ~GoldGolem(){}
    std::string Description() const override{
        return "Gold golem";
    }
};

class Mage : public Unit {
public:
    Mage(){
        costPerUnit = 160;
        meleeAttack = 6;
        rangedAttack = 0;
        meleeDefense = 12;
        rangedDefense = 12;
        hitPoints = 16;
        damage = 3;
        movement = 19;
        speed = 5;
        ammo = 0;
        growth = 8;
    }
    ~Mage(){}
    std::string Description() const override{
        return "Mage";
    }
};

class Naga : public Unit {
public:
    Naga(){
        costPerUnit = 850;
        meleeAttack = 22;
        rangedAttack = 0;
        meleeDefense = 22;
        rangedDefense = 22;
        hitPoints = 90;
        damage = 14;
        movement = 20;
        speed = 7;
        ammo = 0;
        growth = 4;
    }
    ~Naga(){}
    std::string Description() const override{
        return "Naga";
    }
};

class Genie : public Unit {
public:
    Genie(){
        costPerUnit = 550;
        meleeAttack = 10;
        rangedAttack = 0;
        meleeDefense = 18;
        rangedDefense = 18;
        hitPoints = 60;
        damage = 9;
        movement = 25;
        speed = 6;
        ammo = 0;
        growth = 6;
    }
    ~Genie(){}
    std::string Description() const override{
        return "Genie";
    }
};

class Titan : public Unit {
public:
    Titan(){
        costPerUnit = 4000;
        meleeAttack = 32;
        rangedAttack = 32;
        meleeDefense = 32;
        rangedDefense = 32;
        hitPoints = 210;
        damage = 34;
        movement = 21;
        speed = 6;
        ammo = 16;
        growth = 2;
    }
    ~Titan(){}
    std::string Description() const override{
        return "Titan";
    }
};

class DragonGolem : public Unit {
public:
    DragonGolem(){
        costPerUnit = 4000;
        meleeAttack = 34;
        rangedAttack = 0;
        meleeDefense = 34;
        rangedDefense = 34;
        hitPoints = 220;
        damage = 36;
        movement = 27;
        speed = 9;
        ammo = 0;
        growth = 2;
    }
    ~DragonGolem(){}
    std::string Description() const override{
        return "Dragon golem";
    }
};

#endif //HMM4_ACADEMY_UNITS_H
