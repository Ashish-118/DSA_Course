// User function Template for C++

class Solution
{
public:
    int dp[1001][1001];

    int solve(int i, vector<int> &val, vector<int> &wt, int capacity)
    {
        if (i >= val.size() || capacity <= 0)
            return 0;

        if (dp[i][capacity] != -1)
            return dp[i][capacity];

        if (wt[i] > capacity)
        {
            return solve(i + 1, val, wt, capacity);
        }
        int take = val[i] + solve(i, val, wt, capacity - wt[i]);
        int skip = solve(i + 1, val, wt, capacity);

        return dp[i][capacity] = max(take, skip);
    }
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        memset(dp, -1, sizeof(dp));

        return solve(0, val, wt, capacity);
    }
};

// tabulation method

int Tab(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int c = 0; c <= capacity; c++)
        {
            if (wt[i] > c)
            {
                dp[i][c] = dp[i + 1][c];
                continue;
            }
            int take = val[i] + dp[i][c - wt[i]];
            int skip = dp[i + 1][c];

            dp[i][c] = max(take, skip);
        }
    }

    return dp[0][capacity];
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{

    memset(dp, 0, sizeof(dp));

    return Tab(val, wt, capacity);
}

// space optimization

class Solution
{
public:
    int Tab(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<int> prev(capacity + 1, 0), dp(capacity + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int c = 0; c <= capacity; c++)
            {
                int take = 0;
                if (wt[i] <= c)
                {
                    take = val[i] + dp[c - wt[i]];
                }
                int skip = prev[c];
                dp[c] = max(take, skip);
            }
            prev = dp;
        }

        return prev[capacity];
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        return Tab(val, wt, capacity);
    }
};