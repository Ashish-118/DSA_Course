#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int y, k, n;
    cin >> y >> k >> n;

    int reqRem = (k - (y % k)) % k;
    int minVal = reqRem;

    bool check = false;
    for (int i = minVal; i <= n - y; i += k)
    {
        if (i == 0)
            continue;
        cout << i << " ";
        check = true;
    }
    if (!check)
        cout << -1;
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}