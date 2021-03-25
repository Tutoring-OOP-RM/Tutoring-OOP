#include <bits/stdc++.h>

using namespace std;

class B1 {
    int v1, v2;
};

class D : public B1 {
    int t1, t2;
};

int main() {
    cout << "sizeof(D):" << sizeof(D) << '\n'; // 4 x 4 = 16

    // class D : private B1 => sizeof tot 16
}
