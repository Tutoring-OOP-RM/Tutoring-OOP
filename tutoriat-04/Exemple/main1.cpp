#include <bits/stdc++.h>
/*
class B {
    int n;
public:
    void f() {
        std::cout << "Base Class\n";
    }
};*/


class B {
    int n;
public:
    virtual void f() {
        std::cout << "Base Class\n";
    }
};

class D: public B {
    int m;
public:
    void f() {
        std::cout << "Derived Class\n";
    }
};


int main()
{
    std::cout << sizeof(B) << '\n';
    std::cout << sizeof(D) << '\n';
    B b;
    D d;

    B e = d;    //object slicing
    e.f();     

    B* g = &b;  // SIDECAST  
    B* h = &d;  // UPCAST
    g->f();     //B
    h->f();     //fara virtual -> B - (UPCAST); cu virtual -> D

    return 0;
}
