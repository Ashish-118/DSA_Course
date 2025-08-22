class Solution
{
public:
    int solve(int i, int top, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i][top] != -1)
            return dp[i][top];

        int maxi = INT_MIN;
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 || top != j)
            {
                int val = arr[i][j] + solve(i + 1, j, n, arr, dp);
                maxi = max(maxi, val);
            }
        }

        return dp[i][top] = maxi;
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, 0, n, arr, dp);
    }
};

// tabulation method

class Solution
{
public:
    int solve(int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {

        for (int i = n - 1; i >= 0; i--)
        {

            for (int top = 0; top < 3; top++)
            {
                int maxi = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (top != j)
                    {
                        maxi = max(maxi, dp[i + 1][j]);
                    }
                }

                dp[i][top] = maxi + arr[i][top];
            }
        }

        return max({dp[0][0], dp[0][1], dp[0][2]});
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0)); // extra col for top = -1
        return solve(n, arr, dp);
    }
};
