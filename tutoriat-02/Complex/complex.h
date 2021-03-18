#ifndef COMPLEX_H_INCLUDED // directive de preprocesare
#define COMPLEX_H_INCLUDED
#include <bits/stdc++.h>


class Complex {
private:
    int r, i;
public:
    // A se observa valorile default ale parametrilor din constructor
    // => nu tipa atunci cand declar Complex c si vrea constructor fara param
    Complex(int r = 0, int i = 0): r(r), i(i) {}

    // Complex(int r = 0, int i = 0) {
    //     this->r = r;
    //     this->i = i;
    // }
    
    Complex(const Complex&);

    //const -> metoda nu produce modificari clasei
    inline int get_r() const { // recomandat inline la gettere/settere/fct mici
        return r;
    }
    inline int get_i() const {
        return i;
    }
    void print() const;

    std::string toString();
};

#endif // COMPLEX_H_INCLUDED
