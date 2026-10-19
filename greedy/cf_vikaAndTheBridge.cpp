~#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1);
    unordered_map<int, int> idxMap;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        idxMap[c[i]] = 0;
    }

    unordered_map<int, pair<int,int>> mp;

    for (int i = 1; i <= n; i++)
    {
        mp[c[i]] = {-1, -1};
    }

    for (int i = 1; i <= n; i++)
    {
        int plank_cross = i - idxMap[c[i]] - 1;

        auto temp = mp[c[i]];

        if (plank_cross > temp.first)
        {
            mp[c[i]] = {plank_cross, temp.first};
        }
        else
        {
            mp[c[i]]={temp.first, max(temp.second, plank_cross)};

        }

        idxMap[c[i]] = i;
    }

    for (auto &it : mp)
    {
        int plank_cross = n - idxMap[it.first]; // n+1-x-1 == n-x

        auto temp = it.second;

        if (plank_cross > temp.first)
        {
            it.second = {plank_cross, temp.first};
        }
        else
        {
            it.second={temp.first, max(temp.second, plank_cross)};

        }
    }

    int minMax = LLONG_MAX;
    for (auto &it : mp)
    {
        int maxPlank = it.second.first;
        int secondMaxPlank = it.second.second;  

        minMax = min(minMax, max(maxPlank/2, secondMaxPlank));
    }

    cout << minMax << endl;
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