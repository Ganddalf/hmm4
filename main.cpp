#include <iostream>
#include <string>

#include "units/Unit.h"
#include "units/asylum_units.h"
#include "units/academy_units.h"

using namespace std;


class FactionsFactory{
public:
    virtual Tier1Unit *CreateTier1Unit() const = 0;
    virtual Tier2Unit *CreateTier2Unit() const = 0;
    virtual Tier3Unit *CreateTier3Unit() const = 0;
    virtual Tier4Unit *CreateTier4Unit() const = 0;
};

class AsylumFactory : public FactionsFactory {
public:
    Tier1Unit *CreateTier1Unit() const override {
        return new Bandit();
    }
    Tier2Unit *CreateTier2Unit() const override {
        return new Minotaur();
    }
    Tier3Unit *CreateTier3Unit() const override {
        return new Efreet();
    }
    Tier4Unit *CreateTier4Unit() const override {
        return new Hydra();
    }
};

class AcademyFactory : public FactionsFactory {
public:
    Tier1Unit *CreateTier1Unit() const override {
        return new Halfling();
    }
    Tier2Unit *CreateTier2Unit() const override {
        return new Mage();
    }
    Tier3Unit *CreateTier3Unit() const override {
        return new Genie();
    }
    Tier4Unit *CreateTier4Unit() const override {
        return new Titan();
    }
};

void ClientCode(const FactionsFactory &factory) {
    const Tier1Unit *tier1unit = factory.CreateTier1Unit();
    const Tier2Unit *tier2unit = factory.CreateTier2Unit();
    const Tier3Unit *tier3unit = factory.CreateTier3Unit();
    const Tier4Unit *tier4unit = factory.CreateTier4Unit();

    cout << tier1unit->Description() << endl;
    cout << tier2unit->Description() << endl;
    cout << tier3unit->Description() << endl;
    cout << tier4unit->Description() << endl;

    delete tier1unit;
    delete tier2unit;
    delete tier3unit;
    delete tier4unit;
}

int main() {
    FactionsFactory* factory1 = new AsylumFactory();
    FactionsFactory* factory2 = new AcademyFactory();

    cout << "\nIn the Asylum\n";
    ClientCode(*factory1);
    cout << "\nIn the Academy\n";
    ClientCode(*factory2);

    system("pause");
    return 0;
}