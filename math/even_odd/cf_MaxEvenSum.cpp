#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a % 2 == 0 and b % 2 == 0)
    {
        int val = b / 2;
        cout << (a * (val) + 2) << endl;
    }
    else if (a & 1 && b & 1)
    {
        cout << (a * b + 1) << endl;
    }
    else if (a & 1 && b % 2 == 0)
    {
        int val = b / 2;
        if (val & 1)
            cout << -1 << endl;
        else
        {
            cout << (a * (val) + 2) << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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