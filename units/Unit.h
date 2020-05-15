//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_UNIT_H
#define HMM4_UNIT_H


class Unit {
protected:
    int cost;
    int hp;
    int damage;
    int growth;
public:
    virtual ~Unit(){}
    virtual std::string name() const = 0;
    int GetCost(){
        return cost;
    }
    int GetHP(){
        return hp;
    }
    int GetDamage(){
        return damage;
    }
    int GetGrowth(){
        return growth;
    }
};

#endif //HMM4_UNIT_H
