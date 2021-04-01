#include<iostream>
using namespace std;
class A
{ int i;
  public: A(int x=2):i(x+1) {}
  virtual int get_i() { return i; }};
class B: public A
{ int j;
  public: B(int x=20):j(x-2) {}
  virtual int get_j() {return A::get_i()+j; }};
int main()
{ A o1(5);  // i = 6
  B o2;     // i = 3, j = 18
  cout<<o1.get_i()<<" ";    // 6
  cout<<o2.get_j()<<" ";    // 3 + 18 = 21
  cout<<o2.get_i();         // 3
  return 0;
}