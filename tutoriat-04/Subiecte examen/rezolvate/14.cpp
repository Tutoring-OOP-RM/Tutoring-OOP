#include <iostream>
using namespace std;
class A {
protected:
    static int x;
public:
    A(int i = 0) { x = i; }
    virtual A schimb() { return (7 - x); }
};

class B : public A {
public:
    B(int i = 0) { x = i; }
    void afisare() { cout << x; }
};
int A::x = 5;
int main()
{
    A* p1 = new B(18);
    *p1 = p1->schimb();
    // Atentie sa fie ((B*)p1)!!!!!!!!!!!!!!!!
    ((B*)p1)->afisare();    // -11
    // p1->afisare();   // asa nu merge pt ca clasa A nu are functia afisare!!!!!!
    return 0;
}