#include <bits/stdc++.h>

using namespace std;

class B{};

class D : public B {};

int main()
{
    D derived;
    try
    {
        throw derived;
    }

    catch (B b)
    {
        cout << "Caught a base class.\n";
    }

    catch (D d)
    {
        cout << "This won't execute.\n";
    }
    return 0;
}
