class Solution
{
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, vector<vector<int>> &costs, int a_count, int b_count,
              int n)
    {
        if (i >= n)
            return 0;
        if (dp[i][a_count][b_count] != -1)
            return dp[i][a_count][b_count];

        int a = INT_MAX, b = INT_MAX;
        if (a_count)
            a = costs[i][0] + solve(i + 1, costs, a_count - 1, b_count, n);
        if (b_count)
            b = costs[i][1] + solve(i + 1, costs, a_count, b_count - 1, n);

        return dp[i][a_count][b_count] = min(a, b);
    }

    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int a_count = n / 2, b_count = n / 2;
        dp.assign(n + 1, vector<vector<int>>(a_count + 1,
                                             vector<int>(b_count + 1, -1)));
        return solve(0, costs, a_count, b_count, n);
    }
};

// sorting based approach

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<int> refund;
        int N = costs.size() / 2;
        int minCost = 0;
        for (vector<int> cost : costs)
        {
            minCost += cost[0];
            refund.push_back(cost[1] - cost[0]);
        }

        sort(refund.begin(), refund.end());
        for (int i = 0; i < N; i++)
        {
            minCost += refund[i];
        }
        return minCost;
    }
};
