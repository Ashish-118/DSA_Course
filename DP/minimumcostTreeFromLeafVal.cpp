class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> maxi, int left, int right, vector<vector<int>> &dp)
    {
        if (left == right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i + 1, right, dp));
        }

        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        return solve(arr, maxi, 0, n - 1, dp);
    }
};

// tabulation

class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> maxi, vector<vector<int>> &dp)
    {
        int n = arr.size();

        for (int left = n - 1; left >= 0; left--)
        {

            for (int right1 = left + 1; right1 < n; right1++)
            {
                int ans = INT_MAX;

                for (int i = left; i < right1; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right1}] + dp[left][i] +
                                       dp[i + 1][right1]);
                }
                dp[left][right1] = ans;
            }
        }

        return dp[0][n - 1];
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        return solve(arr, maxi, dp);
    }
};