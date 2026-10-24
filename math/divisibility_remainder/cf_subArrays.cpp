#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> rem_prefix(n);
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(-1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int prev = (i > 0 ? rem_prefix[i - 1] : 0);
        rem_prefix[i] = (prev + x) % k;
        auto &tempV = mp[rem_prefix[i]];
        if (tempV.size())
        {
            int tar = i - k;
            int idx = lower_bound(begin(tempV), end(tempV), tar) - begin(tempV);
            ans += idx;
        }
        mp[rem_prefix[i]].push_back(i);
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