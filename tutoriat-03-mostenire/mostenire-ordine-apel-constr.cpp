/*
#include <bits/stdc++.h>

using namespace std;

class B1 {
public:
    B1() {
        cout << "B1\n";
    }
};

class B2 {
public:
    B2() {
        cout << "B2\n";
    }
};

class D : public B1, public B2 {
public:
    D() {
        cout << "D\n";
    }
};

int main() {
    D d;
    return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

class B1 {
public:
    B1() {
        cout << "B1\n";
    }
};

class B2 {
public:
    B2() {
        cout << "B2\n";
    }
};

class D : public B1, public B2 {
public:
    D() : B2(), B1() {
        cout << "D\n";
    }
};

int main() {
    D d;
    return 0;
}
*/



#include <bits/stdc++.h>

using namespace std;

class B1 {
public:
    B1() {
        cout << "B1\n";
    }
};

class B2 {
public:
    B2() {
        cout << "B2\n";
    }
};

// ORDINEA DE APELARE A CONSTRUCTORILOR E CEA DE AICI
class D : public B1, public B2 { // ORDINEA ACEASTA ESTE SFANTA
public:
    D() : B2(), B1(){ // nu conteaza ordinea de aici, dar este fff util
        cout << "D\n";
    }
};

int main() {
    D d; // at! ordinea - B1, B2, D
    return 0;
}
