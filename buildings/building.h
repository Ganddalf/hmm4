//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_BUILDING_H
#define HMM4_BUILDING_H

class Building{
public:
    ~Building(){};
    virtual std::string Description() const = 0;
};

class Hall : public Building {
public:
    ~Hall(){};
    std::string Description() const override {
        return "Hall";
    }
};

class Fort : public Building {
public:
    ~Fort(){};
    std::string Description() const override {
        return "Fort";
    }
};

class Tavern : public Building {
public:
    ~Tavern(){};
    std::string Description() const override {
        return "Tavern";
    }
};

class Prison : public Building {
public:
    ~Prison(){};
    std::string Description() const override {
        return "Prison";
    }
};

class UnitBuilding : public Building {
public:
    ~UnitBuilding(){}
    virtual std::string Description() const = 0;
    virtual Unit* GetUnit() = 0;
};

#endif //HMM4_BUILDING_H
