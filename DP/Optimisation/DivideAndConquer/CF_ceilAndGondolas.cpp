#include <bits/stdc++.h>
using namespace std;
vector<int> dp_curr;
vector<int> dp_before;
vector<vector<int>> prefixSum;

int Cost(int i, int j)
{
    int res = prefixSum[j][j];

    if (i > 0)
    {
        res -= prefixSum[i - 1][j];
        res -= prefixSum[j][i - 1];
        res += prefixSum[i - 1][i - 1];
    }

    return res / 2;
}

void solve(int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;

    pair<int, int> best = {INT_MAX, -1};

    for (int j = optl; j <= min(optr, mid); j++)
    {
        int val = (j ? dp_before[j - 1] : 0) + Cost(j, mid);
        best = min(best, {val, j});
    }

    dp_curr[mid] = best.first;
    int opt = best.second;
    solve(l, mid - 1, optl, opt);
    solve(mid + 1, r, opt, optr);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> u(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> u[i][j];
        }
    }

    prefixSum.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prefixSum[i][j] = u[i][j];
            if (i > 0)
                prefixSum[i][j] += prefixSum[i - 1][j];
            if (j > 0)
                prefixSum[i][j] += prefixSum[i][j - 1];
            if (i > 0 && j > 0)
                prefixSum[i][j] -= prefixSum[i - 1][j - 1];
        }
    }

    dp_curr.assign(n, 0);
    dp_before.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        dp_before[i] = Cost(0, i);
    } // i=0 means, make 0 parition, so we will have one subarray

    for (int i = 1; i < k; i++)
    {
        solve(0, n - 1, 0, n - 1);
        dp_before = dp_curr;
    }

    cout << dp_before[n - 1] << endl;

    return 0;
}