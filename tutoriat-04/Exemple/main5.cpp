// dynamic cast
#include <iostream>

class B {
public:
    virtual void f() {
        std::cout << "B\n";
    }
};

class D: public B{
public:

    void f() override {
        std::cout << "D\n";
    }

};

int main()
{
    B* ob = new D();
    if (dynamic_cast<D*>(ob)) {
        std::cout << "is D\n";
    } else {
        std::cout << "is B\n";
    }
}
