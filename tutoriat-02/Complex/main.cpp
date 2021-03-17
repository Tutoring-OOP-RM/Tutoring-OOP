#include <bits/stdc++.h>
#include "complex.h"

int main() {
    Complex c;  // merge fara constructor - constructorul implicit
    
    c.print();
    // std::cout << c.toString();

    Complex c2(7, 9);

    //std::cout << c2.get_r() << "+" << c2.get_i() <<"i\n";
    //c2.print();
    std::cout << c2.toString();

    std::cout << "Declaring Complex c3(c2)... ";
    Complex c3(c2); // SAU C3=C2
    c3.print();
    
    return 0;
}
