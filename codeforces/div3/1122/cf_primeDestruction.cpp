#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> primeFactors;
vector<int> sieve;

int find_min_ops(int x, int k, vector<int> &dp)
{
    if (x <= k)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    int mini = LLONG_MAX;
    for (auto &ngb : primeFactors[x])
    {
        mini = min(mini, 1 + ngb * find_min_ops(x / ngb, k, dp));
    }

    return dp[x] = mini;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;

    vector<int> dp(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int ret = find_min_ops(x, k, dp);

        ans += ret;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve.assign(200001, true);
    primeFactors.assign(200001, vector<int>());
    int N = 200001;

    sieve[1] = false;
    sieve[0] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!sieve[i])
            continue;

        for (int j = i * i; j <= N; j += i)
        {
            sieve[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (sieve[j] && i % j == 0)
            {
                primeFactors[i].push_back(j);
            }
            int m = i / j;
            if (sieve[m] && i % m == 0)
            {
                primeFactors[i].push_back(m);
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}