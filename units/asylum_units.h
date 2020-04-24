//
// Created by Ganddalf on 24.04.2020.
//

#ifndef HMM4_ASYLUM_UNITS_H
#define HMM4_ASYLUM_UNITS_H

class Bandit : public Unit {
    ~Bandit(){}
    std::string Description() const override{
        return "Bandit";
    }
};

class Orc : public Unit {
    ~Orc(){}
    std::string Description() const override{
        return "Orc";
    }
};

class Medusa : public Unit {
    ~Medusa(){}
    std::string Description() const override{
        return "Medusa";
    }
};

class Minotaur : public Unit {
    ~Minotaur(){}
    std::string Description() const override{
        return "Minotaur";
    }
};

class Nightmare : public Unit {
    ~Nightmare(){}
    std::string Description() const override{
        return "Nightmare";
    }
};

class Efreet : public Unit {
    ~Efreet(){}
    std::string Description() const override{
        return "Efreet";
    }
};

class Hydra : public Unit {
    ~Hydra(){}
    std::string Description() const override{
        return "Hydra";
    }
};

class BlackDragon : public Unit {
    ~BlackDragon(){}
    std::string Description() const override{
        return "Black dragon";
    }
};

#endif //HMM4_ASYLUM_UNITS_H
