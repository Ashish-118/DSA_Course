// #include <bits/stdc++.h>
// #define mod 1000000007

// int add(int a, int b)
// {
//     return (a % mod + b % mod) % mod;
// }

// int mul(int a, int b)
// {
//     return ((a % mod) * 1LL * (b % mod)) % mod;
// }

// int solve(int n, int k, vector<int> &dp)
// {
//     if (n == 1)
//         return k;
//     if (n == 2)
//         return mul(k, k);

//     if (dp[n] != -1)
//         return dp[n];

//     dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));
//     return dp[n];
// }

// int numberOfWays(int n, int k)
// {
//     vector<int> dp(n + 1, -1);
//     return solve(n, k, dp);
// }

/// Tabulation method

#include <bits/stdc++.h>
#define mod 1000000007

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}

int mul(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}

int solve(int n, int k, vector<int> &dp)
{
    dp[1] = k;
    dp[2] = mul(k, k);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }

    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, 0);
    return solve(n, k, dp);
}
