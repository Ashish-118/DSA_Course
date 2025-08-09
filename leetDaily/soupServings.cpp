class Solution
{
public:
    double solve(int a, int b, vector<vector<double>> &dp)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        double ans = 0;
        ans += 0.25 * solve(a - 100, b, dp);
        ans += 0.25 * solve(a - 75, b - 25, dp);
        ans += 0.25 * solve(a - 50, b - 50, dp);
        ans += 0.25 * solve(a - 25, b - 75, dp);

        return dp[a][b] = ans;
    }

    double soupServings(int n)
    {
        if (n >= 4800)
            return 1.0;

        int size = (n + 24) / 25; // scale down problem size
        vector<vector<double>> dp(size + 1, vector<double>(size + 1, -1.0));
        return solve(size, size, dp);
    }
};
