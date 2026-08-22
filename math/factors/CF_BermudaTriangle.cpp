#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int inf = 1e15;
const int mod = 998244353;

inline void solve()
{

    int s, q;
    cin >> s >> q;

    vector<int> fac;
    for (int i = 1; i * i <= s; i += 1)
    {
        if (s % i == 0)
        {
            fac.push_back(i);
            if (i * i != s)
            {
                fac.push_back(s / i);
            }
        }
    }

    sort(fac.begin(), fac.end());

    int n = fac.size();

    vector<int> w(n), h(n);
    vector<int> prew(n + 1), prea(n + 1);

    for (int i = 0; i < n; i += 1)
    {
        w[i] = (fac[i] - (i > 0 ? fac[i - 1] : 0));
        h[i] = s / fac[i];

        prew[i + 1] = prew[i] + w[i];
        prea[i + 1] = prea[i] + w[i] * h[i];
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int ind = lower_bound(fac.begin(), fac.end(), x) - fac.begin();

        int l = 0, r = ind - 1;
        int pos = -1;

        while (l <= r)
        {
            int mid = (l + r) / 2ll;

            if (h[mid] >= y)
            {
                l = mid + 1;
                pos = mid;
            }
            else
                r = mid - 1;
        }

        int ans = prew[pos + 1] * y + (prea[ind] - prea[pos + 1]);

        int prev = (ind == 0 ? 0 : fac[ind - 1]);

        ans += (x - prev) * min(h[ind], y);

        cout << ans << '\n';
    }
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
