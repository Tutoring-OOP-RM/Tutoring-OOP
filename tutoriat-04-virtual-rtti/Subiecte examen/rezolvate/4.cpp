#include <iostream>
class B {
// protected: - trebuie sa adaug PROTECTED ca sa mearga, chiar daca este ~ var. globale, x era private
    static int x;
    int i;

public:
    B()
    {
        x++;
        i = 1;
    }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_i() { return i; }
};
int B::x;

class D : public B {
public:
    D() { x++; }            // error: ‘int B::x’ is private within this context
    ~D() { x--; }           // error: ‘int B::x’ is private within this context
};

int f(B* q)
{
    return (q->get_i()) + 1;       
}
int main()
{
    B* p = new B;
    std::cout << f(p);
    delete p;
    p = new D;
    std::cout << f(p);
    delete p;
    std::cout << D::get_x();
    return 0;
}