/*
#include <bits/stdc++.h>

using namespace std;

class B {
public:
    B() {
        cout << "B\n";
    }
    ~B() {
        cout << "~B\n";
    }
};

class D : private B {
public:
    D() {
        cout << "D\n";
    }
    ~D() {
        cout << "~D\n";
    }
};

int main() {
    D d;
    return 0;
}
*/


#include <bits/stdc++.h>

using namespace std;

class B {
protected:
    int x;
public:
    B() {
        x = 0;
        cout << "B\n";
    }

    B(int x) : x(x) {
    // {
        // this-> x = x_;
        cout << "B cu param\n";

    }

    ~B() {
        cout << "~B\n";
    }
};

class D : public B {
public:
    // D() {
    D(): B(5) {
        cout << "D\n";
    }
    ~D() {
        cout << "~D\n";
    }
};

int main() {
    D d;
    return 0;
}
