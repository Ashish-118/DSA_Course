#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    string p, q;
    cin >> p;
    cin >> q;

    unordered_map<char, int> mp;

    for (auto &c : p)
    {
        mp[c]++;
    }

    for (auto &c : q)
    {
        mp[c]--;
    }

    bool valid = true;

    for (auto it = mp.begin(); it != mp.end();)
    {
        if (it->second < 0)
        {
            valid = false;
            break;
        }
        else if (it->second == 0)
        {
            it = mp.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if (valid)
    {
        if (mp.size() == 3 && mp['s'] == 1 && mp['i'] == 1 && mp['x'] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
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