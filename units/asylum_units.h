//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_ASYLUM_UNITS_H
#define HMM4_ASYLUM_UNITS_H

class Bandit : public Unit {
    ~Bandit(){}
    std::string name() const override{
        return "Bandit";
    }
};

class Orc : public Unit {
    ~Orc(){}
    std::string name() const override{
        return "Orc";
    }
};

class Minotaur : public Unit {
    ~Minotaur(){}
    std::string name() const override{
        return "Minotaur";
    }
};

class Nightmare : public Unit {
    ~Nightmare(){}
    std::string name() const override{
        return "Nightmare";
    }
};

class BlackDragon : public Unit {
    ~BlackDragon(){}
    std::string name() const override{
        return "Black dragon";
    }
};

#endif //HMM4_ASYLUM_UNITS_H
