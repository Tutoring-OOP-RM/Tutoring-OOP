#include <bits/stdc++.h>

class B {
public:
    int n;
    B(int n = 0): n(n){}
    virtual void f() {
        std::cout << "B\n";
    }
};

class D: public B{
public:
    int m;
    D(): B(10){}
    void f(){
        std::cout << "D\n";
    }
};

int main()
{
    // std::cout << sizeof(B) << '\n';
    // std::cout << sizeof(D) << '\n';
    B b;
    D d;

    B* h = &d;  // upcast
  
    B &i = b;   // sidecast
    B &j = d;   // upcast
    std::cout << d.n << " " << j.n << '\n'; // 10 10, desigur
    j.n = 6;
    std::cout << d.n << " " << j.n << '\n'; // 6 6!
    i.f();      //B
    j.f();      //D

    // avem acces la zona lui D\B din h!!!
    static_cast<D*>(h)->m = 77; //CT
    std::cout << d.m << '\n';

    // D* k = &b; a value of type "B *" cannot be used to initialize an entity of type "D *"
    // tot upcast
    D* k = (D*)&b;  // zona specifica lui D este zona reziduala
    k->f(); // B (fara virtual - D!!)

    return 0;
}
