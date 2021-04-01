#include <bits/stdc++.h>

class String {
private:
    char* s;
    size_t len;     // size_t tip de date pt orice dimensiune posibila
                    // size_t e mai special :) for (size_t i...) {}
public:
    String(): s(new char('\0')), len(0) {}

    String(char* other): len(strlen(other)) {
        // de ce nu s = other; ?   - NU!
        //               ==> shallow copy ==> 2 pointeri care pointeaza la aceeasi adresa
        // :D
        
        // Trb sa alocam memorie nouaaa!!
        s = new char[len + 1];
        strcpy(s, other);
    }
    
    // EXTRAA... momentan
    String(const std::string& other): len(other.size()) {
        s = new char[len + 1];
        for (int i = 0; i < len; ++i)
            s[i] = other[i];
        s[len] = '\0';
    }
    
    // copy constructor
    String(const String &other): len(other.len) { // big like pt lista de initializare
        // deep copy pt s
        s = new char[len + 1];
        /*
        for (int i = 0; i < len; i++) {
            s[i] = other.s[i];
        }
        s[len] = '\n';
        */
        // mai rapid asa:
        strcpy(s, other.s);
    }

    // getter
    inline char* get_string() const {
        return s;
    }

    //-----------------niste settere ----------------
    inline void change_ch(unsigned index, char ch) {
        if (index >= len)
            return;
        s[index] = ch;
    }
    char& change_ch2(unsigned index) {
        if (index >= len)
            return s[0];
        return s[index];
    }

    //-----------------------------------------------
/*  String operator = (const String& other) {
        len = other.len;
        strcpy(s, other.s);
    }
*/
    String& operator = (const String& other) { //neaparat String& si nu String
        len = other.len;
        if (this != &other) {   
            delete[] s; // memory leak fara delete[] s;
            s = new char[len + 1];
            strcpy(s, other.s);
        }
        return *this;
    }

    ~String() {
        delete[] this -> s;
    }

    //hopa.... extra
    String(String&& ob): len(std::exchange(ob.len, 0)), s(std::exchange(ob.s, nullptr))
    {
        std::cout << "move constructor\n";
    }

    // operatorul ==
    inline bool operator==(const String& other) {    
        if (len != other.len) {
            return false;
        }
        for (size_t i = 0; i < len; ++i) {
            if (s[i] != other.s[i]) {
                return false;
            }
        }
        return true;
    }

    inline bool operator < (const String& other) {
        if (len < other.len) {
            return true;
        }
        if (len > other.len) {
            return false;
        }
        
        for (size_t i = 0; i < len; i++) {
            if (s[i] != other.s[i]) {
                return s[i] < other.s[i];
            }
        }

        // Q: cum sunt s si other.s aici?
        // A: sunt identice
        return false;
    }
};

String f(String o) {
    return o;
}

int main() {
    String s1 = String(); // String s1;
    String s2("abc cba");

    std::cout << "My string s1 is: " << s1.get_string() << '\n';
    std::cout << "My string s2 is: " << s2.get_string() << '\n';

    std::string raluca = "tudor";

    String s3 = String(raluca);
    std::cout << "My string s3 is: " << s3.get_string() << '\n';

    String s4 = s3;
    s1 = s4;
    std::cout << "My string s4 is: " << s4.get_string() << '\n';
    std::cout << "My string s1 is: " << s1.get_string() << '\n';

    s1.change_ch(1, 'm');
    std::cout << "My string s4 is: " << s4.get_string() << '\n';
    std::cout << "My string s1 is: " << s1.get_string() << '\n';

    s1.change_ch(2, 'm');
    std::cout << "My string s4 is: " << s4.get_string() << '\n';
    std::cout << "My string s1 is: " << s1.get_string() << '\n';

    String s5 = f(s4);
    std::cout << "My string s5 is: " << s5.get_string() << '\n';
    // avem nevoie de move constructor

    return 0;
}
