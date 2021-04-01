#include <bits/stdc++.h>

class Ceva {
public:
    int* v;
    Ceva(): v(new int(8)) {}

    // Ceva(const Ceva&);
};

// Ceva::Ceva(const Ceva& other): v(new int (*other.v)) {
//     std::cout << "CC\n";
// }

int main() {
    Ceva c;
    //demonstratie shallow copy // deep copy
    Ceva c2(c);
    *c2.v = 7;
    std::cout << *c.v;
    
    return 0;
}
