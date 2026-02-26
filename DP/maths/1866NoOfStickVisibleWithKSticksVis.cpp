class Solution
{
public:
    long long dp[1001][1001];
    const int MOD = 1e9 + 7;

    long long solve(int n, int k)
    {
        if (n == k)
            return 1;
        if (n == 0 || k == 0)
            return 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        long long visible = solve(n - 1, k - 1);
        long long hidden = (n - 1) * solve(n - 1, k) % MOD;

        return dp[n][k] = (visible + hidden) % MOD;
    }

    int rearrangeSticks(int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};