#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "units/Unit.h"
#include "units/asylum_units.h"
#include "units/academy_units.h"
#include "buildings/building.h"
#include "buildings/academy_buildings.h"

using namespace std;




class Town{
public:
    std::string name;
    std::vector<Building*> buildings_;
    Town(){
        name = "default";
    }
    Town(std::string name){
        this->name = name;
    }

    void ListBuildings()const{
        std::cout << "Town buildings: ";
        for (size_t i=0; i<buildings_.size(); i++){
            std::cout << buildings_[i]->Description() << ", ";
        }
        std::cout << "\n\n";
    }
    void AvailableUnitBuildings()const{
        std::cout << "Available unit buildings: ";
        for (size_t i=0; i<buildings_.size(); i++){
            UnitBuilding* unitBuilding = dynamic_cast<UnitBuilding*>(buildings_[i]);
            if(unitBuilding){
                cout << unitBuilding->Description() << ", ";
            }
        }
        std::cout << "\n\n";
    }
};


/**
 * Интерфейс Строителя объявляет создающие методы для различных частей объектов
 * Продуктов.
 */
class TownBuilder{
public:
    virtual ~TownBuilder(){}
    virtual void ProduceHall() const =0;
    virtual void ProduceFort() const =0;
    virtual void ProduceTavern() const =0;
    virtual void ProducePrison() const =0;
    virtual void ProduceUnitBuilding11() const =0;
    virtual void ProduceUnitBuilding12() const =0;
    virtual void ProduceUnitBuilding21() const =0;
    virtual void ProduceUnitBuilding22() const =0;
    virtual void ProduceUnitBuilding31() const =0;
    virtual void ProduceUnitBuilding32() const =0;
    virtual void ProduceUnitBuilding41() const =0;
    virtual void ProduceUnitBuilding42() const =0;
};
/**
 * Классы Конкретного Строителя следуют интерфейсу Строителя и предоставляют
 * конкретные реализации шагов построения. Ваша программа может иметь несколько
 * вариантов Строителей, реализованных по-разному.
 */
class AcademyBuilder : public TownBuilder{
private:

    Town* town;

    /**
     * Новый экземпляр строителя должен содержать пустой объект продукта,
     * который используется в дальнейшей сборке.
     */
public:

    AcademyBuilder(){
        this->Reset();
    }

    ~AcademyBuilder(){
        delete town;
    }

    void Reset(){
        this->town = new Town("Academy");
    }
    /**
     * Все этапы производства работают с одним и тем же экземпляром продукта.
     */

    void ProduceHall()const override {
        Hall* hall = new Hall();
        this->town->buildings_.push_back(hall);
    }

    void ProduceFort()const override {
        Fort* fort = new Fort();
        this->town->buildings_.push_back(fort);
    }

    void ProduceTavern()const override {
        Tavern* tavern = new Tavern();
        this->town->buildings_.push_back(tavern);
    }

    void ProducePrison()const override {
        Prison* prison = new Prison();
        this->town->buildings_.push_back(prison);
    }

    void ProduceUnitBuilding11()const override {
        HalflingBurrows* unitBuilding = new HalflingBurrows();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding12()const override {
        DwarvenMines* unitBuilding = new DwarvenMines();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding21()const override {
        GolemFactory* unitBuilding = new GolemFactory();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding22()const override {
        MageTower* unitBuilding = new MageTower();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding31()const override {
        GoldenPavilion* unitBuilding = new GoldenPavilion();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding32()const override {
        AltarOfWishes* unitBuilding = new AltarOfWishes();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding41()const override {
        DragonFactory* unitBuilding = new DragonFactory();
        this->town->buildings_.push_back(unitBuilding);
    }
    void ProduceUnitBuilding42()const override {
        CloudCastle* unitBuilding = new CloudCastle();
        this->town->buildings_.push_back(unitBuilding);
    }
    /**
     * Конкретные Строители должны предоставить свои собственные методы
     * получения результатов. Это связано с тем, что различные типы строителей
     * могут создавать совершенно разные продукты с разными интерфейсами.
     * Поэтому такие методы не могут быть объявлены в базовом интерфейсе
     * Строителя (по крайней мере, в статически типизированном языке
     * программирования). Обратите внимание, что PHP является динамически
     * типизированным языком, и этот метод может быть в базовом интерфейсе.
     * Однако мы не будем объявлять его здесь для ясности.
     *
     * Как правило, после возвращения конечного результата клиенту, экземпляр
     * строителя должен быть готов к началу производства следующего продукта.
     * Поэтому обычной практикой является вызов метода сброса в конце тела
     * метода getProduct. Однако такое поведение не является обязательным, вы
     * можете заставить своих строителей ждать явного запроса на сброс из кода
     * клиента, прежде чем избавиться от предыдущего результата.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsable to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */

    Town* GetTown() {
        Town* result= this->town;
        this->Reset();
        return result;
    }
};

/**
 * Директор отвечает только за выполнение шагов построения в определённой
 * последовательности. Это полезно при производстве продуктов в определённом
 * порядке или особой конфигурации. Строго говоря, класс Директор необязателен,
 * так как клиент может напрямую управлять строителями.
 */
class Director{
    /**
     * @var Builder
     */
private:
    TownBuilder* builder;
    /**
     * Директор работает с любым экземпляром строителя, который передаётся ему
     * клиентским кодом. Таким образом, клиентский код может изменить конечный
     * тип вновь собираемого продукта.
     */

public:

    void set_builder(TownBuilder* builder){
        this->builder=builder;
    }

    /**
     * Директор может строить несколько вариаций продукта, используя одинаковые
     * шаги построения.
     */

    void BuildLittleTown(){
        this->builder->ProduceHall();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
    }

    void BuildMediumTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
        this->builder->ProduceUnitBuilding22();
    }
    void BuildLargeTown(){
        this->builder->ProduceFort();
        this->builder->ProduceHall();
        this->builder->ProduceTavern();
        this->builder->ProducePrison();
        this->builder->ProduceUnitBuilding11();
        this->builder->ProduceUnitBuilding12();
        this->builder->ProduceUnitBuilding22();
        this->builder->ProduceUnitBuilding31();
        this->builder->ProduceUnitBuilding42();
    }
};
/**
 * Клиентский код создаёт объект-строитель, передаёт его директору, а затем
 * инициирует процесс построения. Конечный результат извлекается из объекта-
 * строителя.
 */
/**
 * I used raw pointers for simplicity however you may prefer to use smart
 * pointers here
 */
//void ClientCode(Director& director)
//{
//    AcademyBuilder* builder = new AcademyBuilder();
//    director.set_builder(builder);
//    std::cout << "Standard basic product:\n";
//    director.BuildMinimalViableProduct();
//
//    Town* p = builder->GetTown();
//    p->ListBuildings();
//    delete p;
//
//    std::cout << "Standard full featured product:\n";
//    director.BuildFullFeaturedProduct();
//
//    p= builder->GetTown();
//    p->ListBuildings();
//    delete p;
//
//    // Помните, что паттерн Строитель можно использовать без класса Директор.
//    std::cout << "Custom product:\n";
//    builder->ProducePartA();
//    builder->ProducePartC();
//    p=builder->GetTown();
//    p->ListBuildings();
//    delete p;
//
//    delete builder;
//}

int main(){
    Director* director= new Director();
    AcademyBuilder* builder = new AcademyBuilder();
    director->set_builder(builder);
    int N;
    cout << "Select: little(1), medium(2) or large(3) town: ";
    cin >> N;

    Town* town;

    if(N == 1){
        cout << "Little town\n";
        director->BuildLittleTown();
    } else if(N == 2){
        cout << "Medium town\n";
        director->BuildMediumTown();
    } else if(N == 3){
        cout << "Large town\n";
        director->BuildLargeTown();
    } else {
        delete director;
        delete builder;
        return 0;
    }
    town = builder->GetTown();
    delete builder;
    delete director;

    town->ListBuildings();

    town->AvailableUnitBuildings();

    delete town;
    return 0;
}