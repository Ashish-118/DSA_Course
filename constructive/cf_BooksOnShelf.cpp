#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> ans;
    int count = 0;

    for (auto it : freq)
    {
        ans.push_back(it.first);
        freq[it.first]--;
    }

    for (auto it = freq.rbegin(); it != freq.rend(); it++)
    {
        if (it->second == 0)
        {
            count += 1;
            continue;
        }
        else
        {
            count += 2;
        }

        while (it->second > 0)
        {
            ans.push_back(it->first);
            it->second--;
        }
    }
    cout << count << endl;
    for (auto it : ans)
    {
        cout << it << " ";
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