#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto it = mp.begin(); it != mp.end();)
    {
        if (it->second > 1)
        {
            it = mp.erase(it);
        }
        else
        {
            it++;
        }
    }

    int ans = 0;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (next(it) != mp.end())
        {
            ans = (ans + ((it->first - 1) * (it->first - 1)) % mod) % mod;
        }
    }

    if (!mp.empty())
    {
        ans = (ans + mp.rbegin()->first) % mod;
    }
    cout << ans << endl;
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