
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }

    sort(begin(a), end(a));

    int mini = LLONG_MAX;
    int start = -1, en = -1;
    map<int, int> mp;

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) < mini)
        {
            mini = abs(a[i] - a[i + 1]);
            start = a[i];
            en = a[i + 1];
        }

        mp[a[i]]++;
    }

    mp[a[n - 1]]++;

    mp[start]--;
    mp[en]--;

    a[0] = start;
    a[n - 1] = en;

    if (mp[start] == 0)
    {
        mp.erase(start);
    }

    if (mp.count(en) && mp[en] == 0)
    {
        mp.erase(en);
    }

    int idx = 1;

    // First insert all remaining values >= start.
    auto it = mp.lower_bound(start);

    while (it != mp.end())
    {
        int val = it->first;
        int f = it->second;

        for (int i = 0; i < f && idx < n - 1; i++)
        {
            a[idx++] = val;
        }

        it = mp.erase(it);
    }

    // Then insert all remaining values < start.
    it = mp.begin();

    while (it != mp.end())
    {
        int val = it->first;
        int f = it->second;

        for (int i = 0; i < f && idx < n - 1; i++)
        {
            a[idx++] = val;
        }

        it = mp.erase(it);
    }

    // Finally, place en at the last position.
    a[n - 1] = en;

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
