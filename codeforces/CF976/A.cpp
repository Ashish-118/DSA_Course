

#include <bits/stdc++.h>
using namespace std;

long long count(long long n, long long k)
{
    if (k == 1)
    {
        return n;
    }
    if (n < k)
    {
        return n;
    }
    long long t = k;
    while (t <= n)
    {

        t = t * k;
    }
    t = t / k;
    n -= t;

    return 1 + count(n, k);
}

int main()
{

    int noOfInputsLoops;
    cin >> noOfInputsLoops;
    long long n, k;
    while (noOfInputsLoops--)
    {
        cin >> n >> k;
        cout << count(n, k) << "\n";
    }
}
