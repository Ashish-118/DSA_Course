#include <bits/stdc++.h>
#define int long long
using namespace std;


// exponentiation 
// O(log b)
int solve(int a, int b, int m)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        int t = solve(a, b / 2, m);
        return (t * t) % m;
    }
    else
    {
        int t = solve(a, (b - 1) / 2, m);
        return (a * ((t * t) % m))%m;
    }
}

int32_t main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int a, b, m=1e9+7;
        cin >> a >> b;

        cout << solve(a, b, m)<<endl;
    }

    return 0;
}