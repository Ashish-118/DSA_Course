class Solution
{
public:
    int t[100001];
    int solve(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (t[n] != -1)
        {
            return t[n];
        }
        int ans = INT_MAX;

        for (int k = 1; (k * (k + 1)) / 2 <= n; k++)
        {
            int streakSum = (k * (k + 1)) / 2;
            ans = min(ans, k + 1 + solve(n - streakSum));
        }

        return t[n] = ans;
    }
    int minDays(int n)
    {
        memset(t, -1, sizeof(t));
        return solve(n) - 1;
    }
};