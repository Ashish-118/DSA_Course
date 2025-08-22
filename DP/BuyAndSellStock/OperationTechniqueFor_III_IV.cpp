class Solution
{
public:
    int solve(int operationNo, int index, int k, vector<int> &prices,
              vector<vector<int>> &dp)
    {
        if (index >= prices.size() || operationNo == 2 * k)
            return 0;
        if (dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int buying = 0, sell = 0;
        if (operationNo & 1)
        {
            int sold = prices[index] + solve(operationNo + 1, index + 1, k, prices, dp);
            int notSold = 0 + solve(operationNo, index + 1, k, prices, dp);
            sell = max(sold, notSold);
        }
        else
        {
            int bought = -prices[index] + solve(operationNo + 1, index + 1, k, prices, dp);
            int notBought = 0 + solve(operationNo, index + 1, k, prices, dp);
            buying = max(bought, notBought);
        }

        return dp[index][operationNo] = max(buying, sell);
    }
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));

        return solve(0, 0, k, prices, dp);
    }
};
