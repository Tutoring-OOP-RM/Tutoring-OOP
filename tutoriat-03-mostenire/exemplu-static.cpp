#include <bits/stdc++.h>

using namespace std;

class T {           // size of class = 1
    static int cnt;
public:
    T() {
        cnt++;
    }
    static int countNr() { // functiile statice nu au this, ele au acces doar la campurile statice
        return cnt; // da, e static => ok
    }
    
    ~T() {
        cnt--;
    }
    
};

int T::cnt = 0;

int main() {
    cout << "size of class T = " << sizeof(T) << '\n';
    for (int i = 1; i <= 10; i++) {
    //     cout << "Creating object\n";
        // T x;
    //     cout << "There are " << x.countNr() << " active objects." << '\n';

        T* x = new T; //=> memory leak daca nu dau delete
        cout << x->countNr() << '\n';
        delete x;
    }

    return 0;
}
