#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else if (k == 1 || k == n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 3 << endl;
        int v = min((n - 1) - k, k - 2);
        cout << 1 << " " << k - v << " " << k + v + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}