#include <iostream>
#include <cmath>
using namespace std;

long long func(int fac, long long m)
{
    long long odd = 1;
    long long even = 1;
    long long res = (1LL*odd*even)%m;
    while (fac != 0)
    {

        if (fac & 1)
        {
            odd = 1LL*odd * (fac % m);
        }
        else
        {
            even = 1LL*even * (fac % m);
        }

        cout<<fac;
        fac--;
    }
    return res;
}

int main()
{
    long long m = (pow(10, 9)) + 7;
   cout<< func(212, (m));
    return 0;
}