#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    vector<int> dat(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];

      

        if (b[i] > 0)
        {
            dat[max(0LL, i - b[i] + 1)]++;
            dat[min(n, i + b[i])]--;
        }
    }

    // Prefix sum
    for (int i = 1; i <= n; i++)
    {
        dat[i] += dat[i - 1];
    }

    string ans(n, '0');

    for (int i = 0; i < n; i++)
    {

        if (b[i] == -1)
            continue;

        if (i - b[i] >= 0 && dat[i - b[i]] == 0)
        {
            ans[i - b[i]] = '1';
        }
        else if (i + b[i] < n && dat[i + b[i]] == 0)
        {
            ans[i + b[i]] = '1';
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    // Special case:
    // If no 1 was placed, put it at position 0.
    if (find(ans.begin(), ans.end(), '1') == ans.end())
    {
        ans[0] = '1';
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}