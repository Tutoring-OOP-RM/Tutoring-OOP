// -------------------- PROBLEMA 36 --------------------
/*
#include <iostream>
class cls {
    int x;

public:
    cls(int i) { x = i; }
    int set_x(int i)
    {
        int y = x;
        x = i;
        return y;
    }
    int get_x() { return x; }
};
int main()
{
    cls* p = new cls[10];
    int i = 0;
    for (; i < 10; i++)
        p[i].set_x(i);
    for (i = 0; i < 10; i++)
        std::cout << p[i].get_x(); 
    return 0;
}
*/

// -------------------- PROBLEMA 36 updatata --------------------
/*
#include <iostream>
class cls {
    int x;

public:
    cls(int i = 0) { x = i; }   // valoare default adaugata ulterior
    int set_x(int i)
    {
        int y = x;
        x = i;
        return y;
    }
    int get_x() { return x; }
};
int main()
{
    cls* p = new cls[10];       // no default constructor exists for class "cls"
    int i = 0;
    for (; i < 10; i++)
        p[i].set_x(i);
    for (i = 0; i < 10; i++)
        std::cout << p[i].get_x();  // dupa ca am adaugat o valoare default in constructor 
                                    // pentru a rezolva eroarea, se afiseaza 0123456789
    return 0;
}
*/

// -------------------- PROBLEMA 45 --------------------
/*
#include<iostream>
using namespace std;
class cls
{
    int x;
public: cls(int i=3) {x=i;}
    int &f() const{ return x;} // qualifiers dropped in binding reference of type "int &" to initializer of type "const int"!!!!!
};
int main()
{
    const cls a(-3);
    int b=a.f();
    cout<<b;
    return 0;
}
*/

// https://stackoverflow.com/questions/4957025/const-methods-that-return-references/4957167

// -------------------- PROBLEMA 45 updatata --------------------
/*
#include<iostream>
using namespace std;
class cls
{
    int x;
public: cls(int i=3) {x=i;}
    int f() const {return x;}       // am scos &
};
int main()
{
    const cls a(-3);
    int b=a.f();
    cout<<b;
    return 0;
}
*/

// -------------------- PROBLEMA 61 --------------------
/*
#include <iostream>

class cls {
    int vi;

public:
    cls(int v = 18) { vi = v; }
    operator int() { return vi; }
    cls operator++()
    {
        std::cout << "here\n";
        vi++;
        return *this;
    }
    cls operator++(int);
};

cls cls::operator++(int)
{
    std::cout << "there\n";
    cls aux = *this;
    vi++;
    return aux;
}

int main()
{
    cls p(20);
    int x = p++, y = ++p;
    std::cout << "x=" << x << ", y=" << y << '\n';
}
*/
// Se afiseaza 20, 22
