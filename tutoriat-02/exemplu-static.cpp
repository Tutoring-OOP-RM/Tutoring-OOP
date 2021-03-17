#include <bits/stdc++.h>

using namespace std;

class T { // size of class = 1
    static int cnt; // nu apartine clasei
public:
    T() {
        cnt++;
    }
    static int countNr() { // functiile statice nu au this, ele au acces doar la campurile statice
        return cnt; // da, e static => ok
    }
    /*
    ~T() {
        cnt--;
    }
    */
};

int T::cnt = 0;

int main() {
    cout << "size of class T = " << sizeof(T) << '\n';
    for (int i = 1; i <= 10; i++) {
        cerr << "Creating object\n";
        T x; // creez pe heap nu local
        cout << "There are " << x.countNr() << " active objects." << '\n';

        //T* x = new T; //=> memory leak
        //cout << x->countNr() << '\n';
    }

    return 0;
}
