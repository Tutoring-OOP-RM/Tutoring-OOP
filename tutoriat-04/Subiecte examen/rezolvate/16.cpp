#include <iostream>
using namespace std;
class A {
public:
    int x;
    A(int i = -13) { x = i; std::cout << "cA" <<'\n'; }
};
class B : virtual public A {
public:
    B(int i = -15) { x = i; std::cout << "cB" <<'\n'; }
};
class C : virtual public A {
public:
    C(int i = -17) { x = i; std::cout << "cC" <<'\n'; }
};
class D : virtual public A {
public:
    D(int i = -29) { x = i; std::cout << "cD" <<'\n'; }
};
class E : public B, public D, public C {
public:
    int y;
    E(int i, int j)
        : D(i)
        , B(j)
    {
        std::cout << x << ' ' << i << ' ' << j <<'\n';
        y = x + i + j;
    }
    E(E& ob) { y = ob.x - ob.y; }
};
int main()
{
    E e1(5, 10), e2 = e1; 
    // pt e1 avem y = -17 + 15 = -2, deci pt e2, y = -17 - (-2) = -15
    cout << e2.y;  // -15
    return 0;
}