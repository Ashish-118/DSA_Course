#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> pre(m + 1, 0);

    for (int i = 1; i ;<= m; i++)
    {
        pre[i] = pre[i - 1] + cnt[i];
    }

    vector<int> ans(m + 1, 0);

    for (int k = 1; k <= min(18LL, m); k++)
    {

        for (int v = 1; v <= m; v++)
        {
            int curr_ans = 0;
            for (int i = v; i <= m; i += v)
            {
                curr_ans += ((pre[min(m, i + v - 1)] - pre[i - 1]) * (min(i / v, (1LL << k) - 1LL)));
            }

            int special_idx = v * (1LL << k);
            if (special_idx <= m)
            {
                curr_ans -= (cnt[special_idx] * min(special_idx / v, (1LL << k) - 1LL));
                curr_ans += (cnt[special_idx] * ((1LL << k)));
            }
            ans[k] = max(ans[k], curr_ans);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        ans[i] = max(ans[i], ans[i - 1]);
        cout << ans[i] << " ";
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