#include <iostream>
using namespace std;

class B {
public:
	int x;
	B(int i = 16) { x = i; }
	B f(B ob) { return x + ob.x; }
};
class D : public B {
public:
	D(int i = 25) { x = i; }
	D f(D ob) { return x + ob.x + 1; }
	void afisare() { cout << x; }
};
int main()
{
	D *p1 = new D;
    // LA p2 SE INCEARCA UN DOWNCAST GRESIT!
    // D *p2 = new B;  // a value of type "B *" cannot be used to initialize an entity of type "D *"!!
    // error: invalid conversion from ‘B*’ to ‘D*’
    
    
    D *p2 = new D;
    D *p3 = new D(p1->f(*p2));  // 51 daca pt p2 pun D in D
	cout << p3->x;
	return 0;
}
