// virtual destructor
#include <iostream>

class B {
public:
    virtual ~B() {
        std::cout << "~B\n";
    }
};

class D: public B{
public:
    ~D() {
        std::cout << "~D\n";
    }
};

int main()
{
    B b;
    D d;

    {
        B* e = & b;
        B* f = & d;

        delete e;   // ~B
        delete f;   // ~B fara virtual, ~D ~B cu virtual!
    }

    std::cout << "---\n";

}
