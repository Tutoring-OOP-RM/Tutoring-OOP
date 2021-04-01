// https://www.geeksforgeeks.org/multiple-inheritance-in-c/

#include <bits/stdc++.h>

using namespace std;

class Person {
protected:
    int age;
    const string name;
    double height;
    bool hasLicence;
public:
    //Person() : age(0), name(""), height(0), hasLicence(false) {}
    Person(int age = 0, string name = "", double height = 0, bool hasLicence = false) :
        age(age), name(name), height(height), hasLicence(hasLicence) {}

    friend ostream& operator << (ostream& out, const Person& ob) {
        out << ob.age << ' ' << ob.name << ' ' << ob.height << ' ' << ob.hasLicence << '\n';
        return out;
    }

};

class Programmer : virtual public Person {
protected:
    int loc; // lines of code
public:
    Programmer(int age = 0, string name = "", double height = 0, bool hasLicence = false, int ln = 0) :
        Person(age, name, height, hasLicence), loc(ln) {}

    friend ostream& operator << (ostream& out, const Programmer& ob) {
        out << static_cast <Person> (ob) << ob.loc << '\n';
        return out;
    }
};

class Chef : virtual public Person {
protected:
    vector<string> recipes;
public:
    Chef(int age = 0, string name = "", double height = 0, bool hasLicence = false, vector<string> v={}) :
        Person(age, name, height, hasLicence), recipes(v) {}

    friend ostream& operator << (ostream& out, const Chef& ob) {
        out << static_cast <Person> (ob);
        for (auto it : ob.recipes) {
            out << it << " ";
        }
        out << '\n';
        return out;
    }
};

class ProgrammerChef : public Programmer, public Chef {
private:

public:
    ProgrammerChef(int a = 0, string n = "", double h = 0, bool l = false, int ln = 0, vector<string> v={}) :
        Person(a, n, h, l), Chef(a, n, h, l, v), Programmer(a, n, h, l, ln) {}


    friend ostream& operator << (ostream& out, const ProgrammerChef& ob) {
        out << ob.Chef::age << ' ' << ob.Chef::name << ' ' << ob.Chef::height << ' ' << ob.Chef::hasLicence << ' ' << ob.loc << '\n';
        // out << ob.age << ' ' << ob.name << ' ' << ob.height << ' ' << ob.hasLicence << ' ' << ob.loc << '\n';
        return out;
    }
};

int main() {
    Person P(19, "Nume1", 1.7, true);
    Programmer R(19, "Nume2", 1.6, true, 1e9);
    Chef C(19, "Nume3", 1.65, 1, vector<string>({"lasagna", "cake"}));
    cout << P;
    cout << R;
    cout << C;

    ProgrammerChef pc(19, "Nume4", 1.6, 1, 1e6, vector<string>({"lasagna", "cake"}));
   
    cout << pc;
     cout << sizeof(Person) << " "; 
    cout << sizeof(Programmer) << " " <<sizeof(Chef) << " " << sizeof(ProgrammerChef) << '\n';
}
