//
// Created by potap on 24.04.2020.
//

#ifndef HMM4_ACADEMY_UNITS_H
#define HMM4_ACADEMY_UNITS_H

class Halfling : public Tier1Unit {
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
        return "This is a halfling!";
    }
};

class Dwarf : public Tier1Unit {
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
        return "This is an dwarf!";
    }
};

class GoldGolem : public Tier2Unit {
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
        return "This is a gold golem!";
    }
};

class Mage : public Tier2Unit {
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
        return "This is a mage!";
    }
};

class Naga : public Tier3Unit {
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
        return "This is a naga!";
    }
};

class Genie : public Tier3Unit {
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
        return "This is a genie!";
    }
};

class Titan : public Tier4Unit {
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
        return "Attack on Titan!";
    }
};

class DragonGolem : public Tier4Unit {
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
        return "This is a Dragon Golem!";
    }
};

#endif //HMM4_ACADEMY_UNITS_H
