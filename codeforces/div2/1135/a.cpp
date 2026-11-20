#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int r1 = 1;
    int r2 = n & 1 ? n - 1 : n;

    if (n < 4)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == r1)
        {
            cout << r2 << " ";
        }
        else if (i == r2)
        {
            cout << r1 << " ";
        }
        else
        {
            cout << i << " ";
        }
    }
    cout << endl;
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