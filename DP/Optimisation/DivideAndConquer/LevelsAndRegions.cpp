#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200005;

int n, K;
ld t[N];
ld S[N], A[N], B[N];
ld dp[55][N];

// cost from l+1 → r
inline ld Cost(int l, int r)
{
    return A[r] - A[l] - S[l] * (B[r] - B[l]);
}

void compute(int k, int l, int r, int optl, int optr)
{
    if (l > r)
        return;

    int mid = (l + r) >> 1;

    pair<ld, int> best = {1e18, -1};

    for (int j = optl; j <= min(optr, mid - 1); j++)
    {
        ld val = dp[k - 1][j] + Cost(j, mid);
        if (val < best.first)
            best = {val, j};
    }

    dp[k][mid] = best.first;
    int opt = best.second;

    compute(k, l, mid - 1, optl, opt);
    compute(k, mid + 1, r, opt, optr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> K;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        S[i] = S[i - 1] + t[i];
        A[i] = A[i - 1] + S[i] / t[i];
        B[i] = B[i - 1] + 1.0 / t[i];
    }

    // base case
    for (int i = 1; i <= n; i++)
        dp[1][i] = A[i];

    for (int k = 2; k <= K; k++)
    {
        compute(k, 1, n, 0, n - 1);
    }

    cout << fixed << setprecision(10) << dp[K][n] << "\n";
}