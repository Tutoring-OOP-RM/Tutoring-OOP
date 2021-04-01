#include <bits/stdc++.h>

using namespace std;

class B1 {
protected:
    int v1, v2;
public:
    // B1(): v1(0), v2(1) {}
    B1(int a = 0 , int b = 1) : v1(a), v2(b) {}
    friend ostream& operator << (ostream& os, const B1& obj) {
        os << "b1: " << obj.v1 << ' ' << obj.v2 << '\n';
        return os;
    }
};

class D : public B1 {
    int t1, t2;
public:
    D() :  B1(-3, -5), t1(10), t2(20) {}

    D(int t1, int t2): B1(10, 10), t1(t1), t2(t2) {}
};

int main() {
    D objD;
    D o(1, 2);
    B1 objB(objD); // OBJECT SLICING
    cout << objB; // a construit baza din derivata (a taiat bine derivata)
    // f interesant, stie sa-si ia ceea ce are nevoie
    // datorita mostenirii stie sa taie bine :)
}
