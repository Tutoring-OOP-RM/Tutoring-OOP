#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Vector {
    size_t len;
    std::vector<int*> arr;
public:
    Vector(): len(0) {}
    Vector(const std::vector<int> v): len(v.size()) {
        for (auto& it : v)
            arr.emplace_back(new int(it)); // comparativ cu push_back, emplace_back nu mai face copie - e mai rapid
    }

    Vector(const Vector& other): len(other.len) {
        //assert(other.len == other.arr.size());
        for (auto& it : other.arr)
            arr.emplace_back(new int(*it));
    }
    /*
    void print(){
        for (auto e : arr)
            std::cout << *e << ' ';
        std::cout << '\n';
    }
    */
    // Operator Overloading
    friend ostream& operator << (ostream&, const Vector&);
    friend istream& operator >> (istream&, Vector&);

    Vector operator + (int value) const { // const => nu se modifica this
        Vector v2(*this); // hai sa apelam copy constructor
        // sau Vector v2 = *this;
        for (auto& it : v2.arr)
            (*it) += value;
        return v2;
    }

    friend Vector operator + (int value, const Vector& v){
       return v + value;
    }

    Vector& operator ++() {
        for (auto& it : arr)
            (*it)++;
        return *this;
    }

     Vector operator ++(int) { //punem parametru doar ca sa se diferentieze - int e conventie
        Vector copyv(*this);
        operator ++(); //reusing ++()
        return copyv;
    }

    int& operator [](int index){
        return *arr[index];
    }

    // Destructor
    ~Vector() {
        for (auto & it : arr) {
            delete it;
        }
        arr.clear(); // isi da singur
    }

    Vector & operator = (const Vector & v) {
        len = v.len;
        for (auto & it : arr)
            delete it;
        arr.clear();
        for (auto & it : v.arr)
            arr.push_back(new int(*it));
        return *this;
    }

    bool operator == (const Vector & v) {
        if (len != v.len)
            return 0;
        for (int i = 0; i < (int)arr.size(); i++)
            if (*arr[i] != *(v.arr[i]))
                return 0;
        return 1;
    }

    bool operator < (const Vector &v) {
       for(int i = 0 ; i < min(len, v.len); i++)
            if(*arr[i] != *v.arr[i]) {
                return *arr[i] < *v.arr[i];
            }
        return len < v.len;
   }
};

//-----------------------------
ostream& operator << (ostream& out, const Vector& v) {
    for(auto &it : v.arr){
        out << *it << ' ';
    }
    return out;
}

istream& operator >> (istream& in, Vector& v) {
    in >> v.len;
    /*
    v.arr.resize(v.len);
    for (auto& i : v.arr){
        int x;
        in >> x;
        it = new int(x);
    }
    */
    for (auto& it : v.arr)
        delete it;
    v.arr.clear();
    for (int i = 0; i < v.len; i++) {
        int x;
        in >> x;
        v.arr.emplace_back(new int(x));
    }
}

int main() {
    Vector v = Vector(std::vector<int>({1,-9, 77, 55, -88}));

    std::cout << v << '\n'; // crapa!!!
    // operator << (cout, v) - primul parametru este fluxul
    // de aceea, nu o pot implementa ca metoda!

    //operator << (cout, v) si asa functioneaza

    //v.operator << cout;

    Vector r;
    std::cin >> r;

    r = r + 2;
    cout << r << '\n';

    r = 9 + r;
    cout << r << '\n';

    cout << ++r << '\n';
    cout << r++ << '\n';

    r[1] = 9;
    cout << r << '\n';

    return 0;
}
