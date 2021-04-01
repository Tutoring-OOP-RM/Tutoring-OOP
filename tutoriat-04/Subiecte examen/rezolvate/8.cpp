#include<iostream>
using namespace std;

class B
{
    protected: int x;
    public: B(int i=0) {x=i;}
    virtual B minus() {return (1-x);}
    virtual void afisare() {cout<<x;}
};
class D: public B
{
    public: D(int i=0):B(i) {}
    void afisare() {cout<<x;}
};
int main()
{
    B *p1 = new D(18);  // Aici inainte era D!!
    *p1 = p1->minus();  // no operator "=" matches these operands -- operand types are: D = B
    p1->afisare();
    return 0;
}
