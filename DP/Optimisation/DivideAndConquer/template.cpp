// recursive O(n^2*m)
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int n, m;

// cost function (define this)
long long C(int i, int j)
{
    // example placeholder
    return 0;
}

// recursive function
long long solve(int i, int j)
{

    // Base case: only 1 group
    if (i == 0)
    {
        return C(0, j);
    }

    long long ans = INF;

    for (int k = 0; k <= j; k++)
    {

        long long val;

        if (k == 0)
            val = C(0, j);
        else
            val = solve(i - 1, k - 1) + C(k, j);

        ans = min(ans, val);
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    cout << solve(m - 1, n - 1) << endl;
}
//-----------------------------------------------------------------------
// recurrsive +memo + divide and conquer optimization O(n*m*log(n))

int m, n;
long long dp[5001][5001]; // dp[i][j]

long long C(int i, int j); // cost function (define this)

// compute dp[i][l ... r]
void compute(int i, int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};

    for (int k = optl; k <= min(mid, optr); k++)
    {
        long long val;
        if (k == 0)
            val = C(0, mid);
        else
            val = dp[i - 1][k - 1] + C(k, mid);

        best = min(best, {val, k});
    }

    dp[i][mid] = best.first;
    int opt = best.second;

    compute(i, l, mid - 1, optl, opt);
    compute(i, mid + 1, r, opt, optr);
}

long long solve()
{
    // Base case: i = 0
    for (int j = 0; j < n; j++)
        dp[0][j] = C(0, j);

    // Fill DP rows
    for (int i = 1; i < m; i++)
    {
        compute(i, 0, n - 1, 0, n - 1);
    }

    return dp[m - 1][n - 1];
}

//-----------------------------------------------------------------------
//  optimised

// int m, n;
// vector<long long> dp_before, dp_cur;

// long long C(int i, int j);

// // compute dp_cur[l], ... dp_cur[r] (inclusive)
// void compute(int l, int r, int optl, int optr)
// {
//     if (l > r)
//         return;

//     int mid = (l + r) >> 1;
//     pair<long long, int> best = {LLONG_MAX, -1};

//     for (int k = optl; k <= min(mid, optr); k++)
//     {
//         best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
//     }

//     dp_cur[mid] = best.first;
//     int opt = best.second;

//     compute(l, mid - 1, optl, opt);
//     compute(mid + 1, r, opt, optr);
// }

// long long solve()
// {
//     dp_before.assign(n, 0);
//     dp_cur.assign(n, 0);

//     for (int i = 0; i < n; i++)
//         dp_before[i] = C(0, i);

//     for (int i = 1; i < m; i++)
//     {
//         compute(0, n - 1, 0, n - 1);
//         dp_before = dp_cur;
//     }

//     return dp_before[n - 1];
// }