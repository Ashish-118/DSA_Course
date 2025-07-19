class Solution
{
public:
    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        if (index == satisfaction.size())
            return 0;

        if (dp[index][time] != -1)
            return dp[index][time];

        int inc = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);
        int exc = solve(satisfaction, index + 1, time, dp);

        dp[index][time] = max(inc, exc);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0, dp);
    }
}; // memoization method

// tabulation method

class Solution
{
public:
    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        int n = satisfaction.size();

        for (int i = n - 1; i >= 0; i--)
        {

            for (int t = i; t >= 0; t--)
            {
                int inc = satisfaction[i] * (t + 1) + dp[i + 1][t + 1];
                int exc = dp[i + 1][t];
                dp[i][t] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 0, dp);
    }
};

// space optimized method
class Solution
{
public:
    int solve(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<int> dp(n + 1, 0);

        sort(satisfaction.begin(), satisfaction.end());
        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = 0; t <= i; t++)
            {
                int inc = satisfaction[i] * (t + 1) + dp[t + 1];
                int exc = dp[t];
                dp[t] = max(inc, exc);
            }
        }
        return dp[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {

        return solve(satisfaction);
    }
};