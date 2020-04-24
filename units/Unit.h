//
// Created by potap on 24.04.2020.
//

#ifndef HMM4_UNIT_H
#define HMM4_UNIT_H


class Unit {
protected:
    int costPerUnit;
    int meleeAttack;
    int rangedAttack;
    int meleeDefense;
    int rangedDefense;
    int hitPoints;
    int damage;
    int movement;
    int speed;
    int ammo;
    int growth;
public:
    virtual ~Unit(){};
    virtual std::string Description() const = 0;
};

class Tier1Unit : public Unit {
public:
    virtual ~Tier1Unit(){};
    virtual std::string Description() const = 0;
};

class Tier2Unit : public Unit {
public:
    virtual ~Tier2Unit(){};
    virtual std::string Description() const = 0;
};

class Tier3Unit : public Unit {
public:
    virtual ~Tier3Unit(){};
    virtual std::string Description() const = 0;
};

class Tier4Unit : public Unit {
public:
    virtual ~Tier4Unit(){};
    virtual std::string Description() const = 0;
};

#endif //HMM4_UNIT_H
