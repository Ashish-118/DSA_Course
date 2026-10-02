#include <bits/stdc++.h>
using namespace std;

int val(const string &s)
{
    int ii = 0;
    for (char c : s)
        ii += (c - '0') * (c - '0');
    return ii;
}

int main()
{
    const int n = 1000;
    vector<pair<int, int>> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = i, pos = 0;
        while (true)
        {
            if (cur == 1 || cur == 4)
                break;
            pos++;
            cur = val(to_string(cur));
        }
        dp[i] = {cur, cur == 4 ? pos % 8 : 1};
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int c = 0;
        array<int, 8> cnt{};
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            int x = val(s);
            auto [a, b] = dp[x];
            if (a == 1)
            {
                ans += c;
                c += 1;
            }
            else
            {
                int c = cnt[b];
                ans += c;
                cnt[b] = c + 1;
            }
        }
        cout << ans << '\n';
    }
}
