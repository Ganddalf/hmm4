//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_ACADEMY_UNITS_H
#define HMM4_ACADEMY_UNITS_H

class Halfling : public Unit {
public:
    Halfling(){
        cost = 22;
        hp = 8;
        damage = 1;
        growth = 23;
    }
    ~Halfling(){}
    std::string name() const override{
        return "Полурослик";
    }
};

class Dwarf : public Unit {
public:
    Dwarf(){
        cost = 28;
        hp = 12;
        damage = 2;
        growth = 18;
    }
    ~Dwarf(){}
    std::string name() const override{
        return "Гном";
    }
};

class GoldGolem : public Unit {
public:
    GoldGolem(){
        cost = 240;
        hp = 50;
        damage = 8;
        growth = 6;
    }
    ~GoldGolem(){}
    std::string name() const override{
        return "Золотой голем";
    }
};

class Naga : public Unit {
public:
    Naga(){
        cost = 250;
        hp = 90;
        damage = 14;
        growth = 4;
    }
    ~Naga(){}
    std::string name() const override{
        return "Нага";
    }
};

class Titan : public Unit {
public:
    Titan(){
        cost = 850;
        hp = 210;
        damage = 34;
        growth = 2;
    }
    ~Titan(){}
    std::string name() const override{
        return "Титан";
    }
};

#endif //HMM4_ACADEMY_UNITS_H
