#include <iostream>
using namespace std;

class B {
public:
	int x;
	B(int i = 16) { x = i; }
	// B(){}
	// B f(B ob) { return x + ob.x; }          // ATENTIE NU ESTE VIRTUAL
    virtual B f(B ob) { return x + ob.x; }   
};
class D : public B {
public:
	D(int i = 25) { x = i; }            // class "B" has more than one default constructor !!!!!!!!!
	B f(B ob) { return x + ob.x + 1; }
	void afisare() { cout << x; }
};
int main()
{
	B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));    // class "B" has more than one default constructor
	cout << p3->x;
	return 0;
}

// Dupa ce comentez constructorul fara parametri, se afiseaza 41
// 42 daca f este virtual