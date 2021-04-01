#include <iostream>
using namespace std;
class B { 
    int i;
public: 
    B() { 
        i = 1; 
        cout<<"B ";
    }
    virtual int get_i() { 
        return i; 
    } 
};
class D: virtual public B { 
    int j;
public: 
    D() { 
        j = 2; 
        cout << "D ";
    }
    int get_i() {
        return B::get_i() + j; 
    } 
};
class D2: virtual public B { 
    int j2;
public: 
    D2() { 
        j2 = 3; 
        cout << "D2 "; 
    }
    int get_i() {
        return B::get_i() + j2; 
    } 
};
class MM: public D2, public D { 
    int x;
public: 
    MM() { 
        x = D::get_i() + D2::get_i(); 
        cout << "MM \n"; 
    }
    int get_i() {
        return x; 
    } 
};
int main() 
{ 
    B *o= new MM(); // B D2 D MM
    cout<<o->get_i()<<"\n"; // 7

    MM *p= dynamic_cast<MM*>(o);
    if (p) 
        cout<<p->get_i()<<"\n"; // 7

    D *p2= dynamic_cast<D*>(o);
    if (p2) 
        cout<<p2->get_i()<<"\n";    // tot 7!!!
    return 0;
}