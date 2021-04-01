#include <iostream>
using namespace std;
class B
{ int i;
  public: B() { i=80; }
          virtual int get_i() { return i; }
};
class D: public B
{ int j;
  public: D() { j=27; }
          int get_j() {return j; }
};
int main() { 
  // SE INCEARCA UN DOWNCAST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! EROARE!!!!!!!!!!!!!!!!!!1
  D* p = new B; // a value of type "B *" cannot be used to initialize an entity of type "D *"
  cout<<p->get_i();
  cout<<((D*)p)->get_j();
  return 0;
}
