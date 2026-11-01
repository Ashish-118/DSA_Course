#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int inf = 1e15;
const int mod = 998244353;

inline void solve()
{

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    auto check = [&](int cur)
    {
        vector<int> a;

        for (int i = 0; i < n; i += 1)
        {
            if (i == 0)
            {
                if (v[i + 1] - v[i] > cur)
                {
                    a.push_back(v[i]);
                }
            }
            else if (i == n - 1)
            {
                if (v[i] - v[i - 1] > cur)
                {
                    a.push_back(v[i]);
                }
            }
            else
            {
                if (v[i + 1] - v[i] > cur && v[i] - v[i - 1] > cur)
                {
                    a.push_back(v[i]);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < a.size(); i += 1)
        {
            if (i < a.size() - 1 && a[i + 1] - a[i] <= 2 * cur)
            {
                i += 1;
            }

            ans += 1;
        }

        return ans <= k;
    };

    int l = 1, r = inf;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2ll;

        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans;
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
        cout << '\n';
    }
    return 0;
}