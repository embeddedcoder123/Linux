# Design Pattern
## 1. Singleton
> Singleton class in C++ is the class that is designed to provide only one unique instance across the system. So, whenever we create c++  singleton instance, it will return the same instance created earlier if any.

Singleton class requires below methods and variables.

1. Private singleton constructor and copy Constructor : 
    - Singleton class should not allow users to create singleton instances but they should request  class to return an instance.Hence, make the constructor and copy constructor of singleton class private to prevent object instantiation.
 
2. A public static function:
    - As, it has blocked users to create objects, there should be a static function that returns object to the users using class name.
 
3. A private static pointer: 
    - We need a static class pointer in singleton class to allocate object that will be returned to users. Why static pointer, as static function accepts only static variables as a parameter.

### concept code
```cpp 
#include <iostream>
using namespace std;

class Singleton {
        static Singleton *instance;
        int data;
        
        // Private constructor so that no objects can be created.
        Singleton() {
            data = 0;
        }

   public:
        static Singleton* getInstance() {
            if (!instance) instance = new Singleton;

            return instance;
        }

        int getData() {
            return this->data;
        }

        void setData(int data) {
            this->data = data;
        }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance

Singleton* Singleton::instance = 0;

int main() {
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;
   return 0;
}

```

### Logger class
```cpp
#include <iostream>
using namespace std;

//singlton design 
class logger{
    logger(){} // So we can avoid define instance of class
    static logger* instance;
    public:
        static logger* getInstance(){
            if(instance == nullptr) instance = new logger();
            return instance;
        }
        
        void printLogs(){
            cout<<"Prints logs \n";
        }
};

logger* logger::instance = nullptr;
int main()
{
    logger* obj = logger::getInstance();
    obj->printLogs();
    std::cout<<"Hello World";

    return 0;
}
```
------------------------
## Observer pattern

```cpp
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
class Observer{// abstract class
 public:
 virtual void notify() const = 0;
 virtual ~Observer(){};
};

class Subject{
 list<Observer*>observers;
 public:
 Subject(){
   cout<<"Sub const "<<endl;
 }
 void registerObserver(Observer* obj){
   cout<<typeid(*obj).name()<<" is register"<<endl;
   observers.push_back(obj);
 }
 
 void unregisterObserver(Observer* obj){
   cout<<typeid(*obj).name()<<" is unregister"<<endl;
   observers.remove(obj);
 }

 void notifyObserver() const{
   for(auto obj : observers){
     obj->notify();
   }
 }
 
};

class ConcreteObserverA : public Observer{
 public:
 ConcreteObserverA (Subject& sub){
   sub.registerObserver(this);
 }
 void notify() const override {
   std::cout << "ConcreteObserverA::notify\n";
 }

};

class ConcreteObserverB : public Observer{
 public:
 ConcreteObserverB (Subject& sub){
   sub.registerObserver(this);
 }
 void notify() const override {
   std::cout << "ConcreteObserverB::notify\n";
 }

};
int main() {
 
 Subject sub;
 ConcreteObserverA objA(sub);
 ConcreteObserverB objB(sub);

 sub.notifyObserver();
 
 sub.unregisterObserver(&objA);
 
 sub.notifyObserver();
 return 0;
}
/*
Output:
Sub const 
17ConcreteObserverA is register
17ConcreteObserverB is register
ConcreteObserverA::notify
ConcreteObserverB::notify
17ConcreteObserverA is unregister
ConcreteObserverB::notify
*/
```



```cpp

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Observer interface
class Observer {
public:
    virtual void notify(float temperature) = 0;
    virtual ~Observer() = default;
};

// Subject
class TemperatureMonitor {
private:
    list<Observer*> observers;
    float temperature = 0.0f;

public:
    void registerObserver(Observer* obj) {
        if (obj &&
            find(observers.begin(), observers.end(), obj)
                == observers.end()) {
            observers.push_back(obj);
        }
    }

    void unregisterObserver(Observer* obj) {
        observers.remove(obj);
    }

    void setTemperature(float temp) {
        temperature = temp;

        cout << "\nCoolant temperature: "
             << temperature << " C\n";

        notifyObservers();
    }

    void notifyObservers() {
        for (auto obj : observers) {
            obj->notify(temperature);
        }
    }
};

// Observer 1: Cooling fan controller
class CoolingFan : public Observer {
public:
    void notify(float temperature) override {
        if (temperature >= 100.0f) {
            cout << "Fan: HIGH speed\n";
        } else if (temperature >= 90.0f) {
            cout << "Fan: LOW speed\n";
        } else {
            cout << "Fan: OFF\n";
        }
    }
};

// Observer 2: Instrument cluster
class Dashboard : public Observer {
public:
    void notify(float temperature) override {
        if (temperature >= 105.0f) {
            cout << "Dashboard: HIGH TEMP WARNING!\n";
        } else {
            cout << "Dashboard: Temperature normal\n";
        }
    }
};

// Observer 3: Diagnostic logger
class DiagnosticLogger : public Observer {
public:
    void notify(float temperature) override {
        cout << "Logger: Recorded "
             << temperature << " C\n";
    }
};

int main() {
    TemperatureMonitor monitor;

    CoolingFan fan;
    Dashboard dashboard;
    DiagnosticLogger logger;

    monitor.registerObserver(&fan);
    monitor.registerObserver(&dashboard);
    monitor.registerObserver(&logger);

    monitor.setTemperature(85.0f);
    monitor.setTemperature(95.0f);
    monitor.setTemperature(105.0f);

    monitor.unregisterObserver(&logger);

    return 0;
}
```
------------------------

## Builder design patttern

```cpp
#include <iostream>
#include <string>

// Product class
class Pizza {
public:
	void setDough(const std::string& dough)
	{
		this->dough = dough;
	}

	void setSauce(const std::string& sauce)
	{
		this->sauce = sauce;
	}

	void setTopping(const std::string& topping)
	{
		this->topping = topping;
	}

	void displayPizza() const
	{
		std::cout<< "Pizza with Dough: " << dough
				<< ", Sauce: " << sauce
				<< ", Topping: " << topping << std::endl;
	}

private:
	std::string dough;
	std::string sauce;
	std::string topping;
};

// Abstract builder class
class PizzaBuilder {
public:
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	virtual Pizza getPizza() const = 0;
};


// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Pan Dough");
	}

	void buildSauce() override
	{
		pizza.setSauce("Hawaiian Sauce");
	}

	void buildTopping() override
	{
		pizza.setTopping("Ham and Pineapple");
	}

	Pizza getPizza() const override { return pizza; }

private:
	Pizza pizza;
};

// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Thin Dough");
	}

	void buildSauce() override
	{
		pizza.setSauce("Spicy Tomato Sauce");
	}

	void buildTopping() override
	{
		pizza.setTopping("Pepperoni and Jalapenos");
	}

	Pizza getPizza() const override { return pizza; }

private:
	Pizza pizza;
};

// Director class that orchestrates the construction
class Cook {
public:
	void makePizza(PizzaBuilder& builder)
	{
		builder.buildDough();
		builder.buildSauce();
		builder.buildTopping();
	}
};

int main()
{
	Cook cook;

	HawaiianPizzaBuilder hawaiianBuilder;
	cook.makePizza(hawaiianBuilder);
	Pizza hawaiianPizza = hawaiianBuilder.getPizza();
	hawaiianPizza.displayPizza();

	SpicyPizzaBuilder spicyBuilder;
	cook.makePizza(spicyBuilder);
	Pizza spicyPizza = spicyBuilder.getPizza();
	spicyPizza.displayPizza();

	return 0;
}

```


```cpp

#include <iostream>
#include <cstdint>

// Product: CAN configuration
struct CanConfig {
    uint32_t bitrate = 0;
    uint32_t txId = 0;
    uint32_t rxId = 0;
    bool loopback = false;
};

// Abstract Builder
class CanBuilder {
public:
    virtual void buildBitrate() = 0;
    virtual void buildMode() = 0;
    virtual void buildFilters() = 0;
    virtual CanConfig getConfig() const = 0;

    virtual ~CanBuilder() = default;
};

// Concrete Builder: Production ECU
class ProductionCanBuilder : public CanBuilder {
    CanConfig config;

public:
    void buildBitrate() override {
        config.bitrate = 500000;
    }

    void buildMode() override {
        config.loopback = false;
    }

    void buildFilters() override {
        config.txId = 0x101;
        config.rxId = 0x201;
    }

    CanConfig getConfig() const override {
        return config;
    }
};

// Concrete Builder: Test ECU
class TestCanBuilder : public CanBuilder {
    CanConfig config;

public:
    void buildBitrate() override {
        config.bitrate = 250000;
    }

    void buildMode() override {
        config.loopback = true;
    }

    void buildFilters() override {
        config.txId = 0x700;
        config.rxId = 0x708;
    }

    CanConfig getConfig() const override {
        return config;
    }
};

// Director
class CanDirector {
public:
    void construct(CanBuilder& builder) {
        builder.buildBitrate();
        builder.buildMode();
        builder.buildFilters();
    }
};

// Hardware driver simulation
class CanController {
public:
    bool initialize(const CanConfig& config) {
        if (config.bitrate == 0) {
            std::cout << "Invalid CAN bitrate\n";
            return false;
        }

        std::cout << "CAN initialized\n";
        std::cout << "Bitrate: " << config.bitrate << '\n';
        std::cout << "TX ID: 0x" << std::hex
                  << config.txId << '\n';
        std::cout << "RX ID: 0x"
                  << config.rxId << std::dec << '\n';
        std::cout << "Mode: "
                  << (config.loopback ? "Loopback" : "Normal")
                  << '\n';

        return true;
    }
};

int main() {
    CanDirector director;
    CanController controller;

    ProductionCanBuilder production;
    director.construct(production);

    CanConfig productionConfig = production.getConfig();
    controller.initialize(productionConfig);

    std::cout << "\n--- Test configuration ---\n";

    TestCanBuilder test;
    director.construct(test);

    CanConfig testConfig = test.getConfig();
    controller.initialize(testConfig);

    return 0;
}

```
## Factory design patter

// Factory Methods

```cpp
#include<iostream>
#include<cstring>
using namespace std;
enum  enumVehicle{
    TwoWheel = 0,
    FourWheel =
};


// Abract Class
class vehicle{
    public:
    virtual void name() = 0;
};

// Product 1
class TwoWheeler : public vehicle{
    public:
    void name(){
            cout<<"TwoWheeler\n";
        }
};

// Product 2
class FourWheeler : public vehicle {
    public:
    void name(){
            cout<<"FourWheeler\n";
        }
};

class client {
    vehicle* ptr = nullptr;

    public:
    client(enumVehicle obj){
        if(obj == TwoWheel ){
            ptr = new TwoWheeler();
        }
        else if(obj == FourWheel){
            ptr = new FourWheeler();
        }
    }
	vehicle* getVehicle(){
			return ptr;
		}
		
	~client(){
			if(ptr) delete ptr;
	}
	   
};
int main()
{
    client TwoWheelObj(TwoWheel);
    vehicle * twoWheelerObj = TwoWheelObj.getVehicle();
    twoWheelerObj->name();
   
    client FourWheelObj(FourWheel);
    vehicle * FourWheelerObj = FourWheelObj.getVehicle();
    FourWheelerObj->name();
   return 0;
}
```
1. In the above example, we have totally decoupled the selection of types 
   for object creation from the Client. 
2. The factory class is now responsible for deciding which object type 
   to create based on the input provided by the client. 
3. The client just needs to make calls to the factory class’ build method and 
   pass the type it wants without worrying about the actual implementation of 
   the creation of objects.

## Abstarct factory design pattern

```cpp
#include <iostream>
using namespace std;
#define TATA


class Company {
    public:
   	 Company() {
     		 id_ = total_++;
   	  }
    virtual void companyName() = 0;
    protected:
      int id_;
      static int total_;
};
int Company::total_ = 0;


//Product A1
class TataMotor: public Company {
  	public:
    void companyName() {
      cout << "TataMotor " << id_ << ": companyName" << endl;
    }
};

//Product A2
class TataPower : public Company {
  public:
    void companyName() {
      cout << "TataPower " << id_ << ": companyName" << endl;
    }
};


//Product B1
class AdaniMotor : public Company {
  public:
    void companyName() {
      cout << "AdaniMotor " << id_ << ": companyName" << endl;
    }
};

//Product B2
class AdaniPower : public Company {
  public:
    void companyName() {
      cout << "AdaniPower " << id_ << ": companyName" << endl;
    }
};

class Factory {
  public:
    virtual Company* powerCompanyInstance() = 0;
    virtual Company* motorCompanyInstance() = 0;
};

// Concrete factory1
class TataFactory : public Factory {
  public:
    Company* motorCompanyInstance() {
      return new TataMotor;
    }
    Company* powerCompanyInstance() {
      return new TataPower;
    }
};

// Concrete factory2
class AdaniFactory : public Factory {
  public:
    Company* motorCompanyInstance() {
      return new AdaniMotor;
    }
    Company* powerCompanyInstance() {
      return new AdaniPower;
    }
};

int main() {
#ifdef TATA
  Factory* factory = new TataFactory;
#elifdef ADANI
  Factory* factory = new AdaniFactory;
#endif
  Company* Companys[3];

  Companys[0] = factory->motorCompanyInstance(); 
  Companys[1] = factory->powerCompanyInstance(); 
  Companys[2] = factory->motorCompanyInstance();

  for (int i=0; i < 3; i++) {
    Companys[i]->companyName();
  }
  return 0;
}




/*
TataMotor 0: companyName
TataPower 1: companyName
TataMotor 2: companyName
*/
```

```cpp
#include <iostream>
using namespace std;

class CanDriver {
public:
    virtual void init() = 0;
    virtual ~CanDriver() = default;
};

class PowerDriver {
public:
    virtual void init() = 0;
    virtual ~PowerDriver() = default;
};

class BoardACan : public CanDriver {
public:
    void init() override {
        cout << "Board A CAN initialized\n";
    }
};

class BoardAPower : public PowerDriver {
public:
    void init() override {
        cout << "Board A power monitor initialized\n";
    }
};

class BoardBCan : public CanDriver {
public:
    void init() override {
        cout << "Board B CAN initialized\n";
    }
};

class BoardBPower : public PowerDriver {
public:
    void init() override {
        cout << "Board B power monitor initialized\n";
    }
};

// Abstract Factory
class HardwareFactory {
public:
    virtual CanDriver& getCan() = 0;
    virtual PowerDriver& getPower() = 0;
    virtual ~HardwareFactory() = default;
};

// Concrete Factory A: static allocation
class BoardAFactory : public HardwareFactory {
    BoardACan can;
    BoardAPower power;

public:
    CanDriver& getCan() override {
        return can;
    }

    PowerDriver& getPower() override {
        return power;
    }
};

// Concrete Factory B: static allocation
class BoardBFactory : public HardwareFactory {
    BoardBCan can;
    BoardBPower power;

public:
    CanDriver& getCan() override {
        return can;
    }

    PowerDriver& getPower() override {
        return power;
    }
};

void startEcu(HardwareFactory& factory) {
    factory.getCan().init();
    factory.getPower().init();
}

int main() {
    BoardAFactory factory;
    startEcu(factory);
}
```