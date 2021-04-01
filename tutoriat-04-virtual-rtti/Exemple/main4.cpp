// final keyword
#include <iostream>


// Obs class B final => eroare la linia 16 class D:public B (cannot derive from final base)
class B {
public:
    virtual void f() final {
        std::cout << "B\n";
    }
};

class D: public B{
public:
    /*
    void f() override { //cannot override 'final' function "B::f" (declared at line 8)
        std::cout << "D\n";
    }
    */
};

int main()
{
    B b;
    D d;
}
