#include <bits/stdc++.h>

using namespace std;

class C{
public:
	C(){cout << "CC ";}
};

class B{
public:
	B(){cout << "CB ";}
}c;

class D : public B{
public:
    D(){cout << "CD ";}
    C c;
};

class E : public D{
public:
    E(){cout << "CE ";}
}b;

int main()
{
    E e1, e2;
    B b;
}


// Compilează? DA
// Ce se va afişa?
// CB   CB CC CD CE   CB CC CD CE    CB CC CD CE     CB 
// c         b             e1             e2          b

// pt E avem nevoie de D, dar pt D avem compoziție...

// (dacă facem D b, se apelează constructor B (CB) APOI CC APOI CD) )
// Atenție - variabilele globale nu se execută neaparat in această ordine!

// Reamintim şi că ordinea de apelare a destructorilor este inversă constructorilor.
