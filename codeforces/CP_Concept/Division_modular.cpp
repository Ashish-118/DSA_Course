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
        t = (1ll * t * t) % m;
        return ( a * t % m);
    }
}

int inverse(int x, int m)
{
    return solve(x, m - 2, m);
}
int32_t main()
{

    int a, b, m;
    cin >> a >> b>>m;

    // cout << solve(a, b, m)<<endl;
    int res1 = (a / b) % m;

    a = a % m;

    int inv_b = inverse(b, m);
    // cout<<inv_b<<endl;
    int res2 = a * inv_b % m;
    cout << res1 << " " << res2 << endl;

    return 0;
}