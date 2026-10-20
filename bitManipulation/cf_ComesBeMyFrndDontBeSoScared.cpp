#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m1;
    cin >> n >> m1;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int m = (n + 1) / 2;
    int temp = m;
    cout << m << endl;

    for (int i = 1; i <= n; i++)
    {
        if (!temp)
        {
            break;
        }
        cout << i << " " << i + (m - 1) << endl;
        temp--;
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