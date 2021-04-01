#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

class Car {
protected:
    int power;
public:
    Car(int p = 0): power(p) {}
    virtual void calculateConsumption() = 0; // clasa abstracta, nu putem instantia
};

class ElectricCar:public Car {
    int amp;
public:
    ElectricCar(int power, int amp = 0): Car(power), 
                                         amp(amp) {}
    void calculateConsumption() override {
        std::cout << "consumption = " << amp * power << " - electric car\n";
    }
    inline int get_amp() const {
   	    return this->amp;
    }

};

class GasCar : public Car{
    int fuel_tank_capacity;

public:
    GasCar(int power , int c = 0): Car(power), 
                                   fuel_tank_capacity(c) {}
    void calculateConsumption() override {
        std::cout << "consumption = " << pow(power * fuel_tank_capacity, 2)<< " - gas car\n";
    }
};


int main()
{
    srand(time(nullptr));
    std::vector<Car*> v(10);
    for (int i = 0; i < v.size(); ++i) {
        if (rand() % 2) {
            v[i] = new ElectricCar(i, rand() % 10 * i);
        } else {
            v[i] = new GasCar(i + 15, rand() % 20 * (i + 1));
        }    
    }
	
    for (auto & i : v) {
        i->calculateConsumption();
    }

    for (auto & it : v) {
        if (dynamic_cast<GasCar*> (it)) {
            std::cout <<"Benzina\n";
        } else {
            std::cout<<"Electrica\n";
        }
    }

    for (auto& it : v)
   	    if (ElectricCar* electric_it =  dynamic_cast <ElectricCar*> (it))
   		    std::cout << electric_it->get_amp() << '\n';

   return 0;
}
