//
// Created by potap on 24.04.2020.
//

#ifndef HMM4_ASYLUM_UNITS_H
#define HMM4_ASYLUM_UNITS_H

class Bandit : public Tier1Unit {
    ~Bandit(){}
    std::string Description() const override{
        return "This is a bandit!";
    }
};

class Orc : public Tier1Unit {
    ~Orc(){}
    std::string Description() const override{
        return "This is an orc!";
    }
};

class Medusa : public Tier2Unit {
    ~Medusa(){}
    std::string Description() const override{
        return "This is a medusa!";
    }
};

class Minotaur : public Tier2Unit {
    ~Minotaur(){}
    std::string Description() const override{
        return "This is a minotaur!";
    }
};

class Nightmare : public Tier3Unit {
    ~Nightmare(){}
    std::string Description() const override{
        return "This is a nightmare!";
    }
};

class Efreet : public Tier3Unit {
    ~Efreet(){}
    std::string Description() const override{
        return "This is an efreet!";
    }
};

class Hydra : public Tier4Unit {
    ~Hydra(){}
    std::string Description() const override{
        return "Hail Hydra!";
    }
};

class BlackDragon : public Tier4Unit {
    ~BlackDragon(){}
    std::string Description() const override{
        return "Wooooouh! This is a king - Black Dragon!";
    }
};

#endif //HMM4_ASYLUM_UNITS_H
