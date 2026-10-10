#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        auto check = [&](int i, int v)
        {
            if (i >= 0)
                return v == a[i] + a[i + 2] - a[i + 4];
            return false;
        };

        unordered_map<int, int> cnt;
        long long ans = 0;

        for (int i = 0; i < n - 4; i++)
        {
            int v = a[i] + a[i + 2] - a[i + 4];
            int c = cnt[v];
            int oc = check(i - 2, v) + check(i - 4, v);
            ans += c - oc;
            cnt[v] = c + 1;
        }

        cout << ans << '\n';
    }
}
