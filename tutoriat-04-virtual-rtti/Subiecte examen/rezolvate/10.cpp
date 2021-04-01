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
float f(int& y)
{
    cout << "y este referinta";
    return (float)y / 2;
}
int main()
{
    int x;
    try {
        cout << "Da - mi un numar par : ";
        cin >> x;
        if (x % 2)
            x = f(x, 0);
        else
            x = f(x);   // !!!!!!! more than one instance of overloaded function "f" matches the argument list: 
            // -- function "f(int y)" -- function "f(int &y)" -- argument types are: (int)
        cout <<"Numarul "<< x <<" e bun !"<< endl;
    }
    catch (int i) {
        cout <<"Numarul "<< i <<" nu e bun !"<< endl;
    }
    return 0;
}