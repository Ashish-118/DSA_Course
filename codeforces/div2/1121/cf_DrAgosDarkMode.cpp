#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(s) (int)s.size()
#define all(v) (v).begin(), (v).end()

const int mod = 998244353;

long long f(const string &s)
{
    int n = s.size();

    vector<int> cnt(3);
    cnt[0] = 1;

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += (s[i - 1] - '0') * (i % 2 == 0 ? 1 : -1);
        sum = (sum + 3) % 3;
        cnt[sum]++;
    }

    long long ans = 0;

    for (auto c : cnt)
    {
        ans += c * (c - 1) / 2;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    if (n < 3)
    {
        cout << string(n, '1') << endl;
        return;
    }

    string optimal;
    long long min_f = LLONG_MAX;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {

                string cur(n, '0');

                cur[n / 3 + i - 1] = '1';
                cur[(2 * n) / 3 + j - 1] = '1';
                cur[n - 1] = (char)('0' + k);

                long long f_val = f(cur);

                if (f_val < min_f)
                {
                    optimal = cur;
                    min_f = f_val;
                }
            }
        }
    }

    cout << optimal << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases = 1;
    cin >> testcases;

    while (testcases--)
    {
        solve();
    }

    return 0;
}