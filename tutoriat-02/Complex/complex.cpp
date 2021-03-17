#include "complex.h"

Complex::Complex(const Complex& other): r(other.r), i(other.i) {
    std::cout << "CC\n";
}

void Complex::print() const {
    std::cout << this -> r << '+' << this -> i << "i\n";
}
std::string Complex::toString() {
    return std::to_string(this -> r) + "+" + std::to_string(this -> i) + "i\n";
}
