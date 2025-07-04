// #define MOD 1000000007
// #include <vector>

// long long int solveMem(vector<long long int> &dp, int n)
// {
//     if (n == 1)
//         return 0;
//     if (n == 2)
//         return 1;

//     if (dp[n] != -1)
//         return dp[n];
//     dp[n] = (((n - 1) % MOD) * (solveMem(dp, n - 2) % MOD + solveMem(dp, n - 1) % MOD)) % MOD;
//     return dp[n];
// }

// long long int countDerangement(int n)
// {
//     vector<long long int> dp(n + 1, -1);
//     return solveMem(dp, n);
// }

// tabulation method

// #define MOD 1000000007
// #include <vector>

// long long int countDerangement(int n)
// {
//     vector<long long int> dp(n + 1, 0);

//     dp[2] = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         int ans = (((i - 1) % MOD) * (dp[i - 2] % MOD + dp[i - 1] % MOD)) % MOD;
//         dp[i] = ans;
//     }

//     return dp[n];
// }

// space optimized method

#define MOD 1000000007
#include <vector>

long long int countDerangement(int n)
{
    long long int prev1 = 0;
    long long int prev2 = 1;

    for (int i = 3; i <= n; i++)
    {
        int ans = (((i - 1) % MOD) * (prev1 % MOD + prev2 % MOD)) % MOD;
        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}