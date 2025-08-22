class Solution
{
public:
    int solve(bool bought, int val, int index, vector<int> &prices)
    {

        if (index >= prices.size())
            return 0;

        int buy = 0;
        int sell = 0;
        if (!bought)
        {
            int buyhere = solve(true, prices[index], index + 1, prices);
            int notbuy = solve(false, 0, index + 1, prices);
            buy = max(buyhere, notbuy);
        }
        else
        {
            int sellhere = prices[index] - val + solve(false, 0, index + 1, prices);
            int notsell = solve(true, val, index + 1, prices);
            sell = max(sellhere, notsell);
        }

        return max(buy, sell);
    }
    int maxProfit(vector<int> &prices)
    {

        return solve(false, 0, 0, prices);
    }
};

// memoization

class Solution
{
public:
    int solve(int bought, int index, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (index >= prices.size())
            return 0;
        if (dp[index][bought] != -1)
            return dp[index][bought];
        int buy = 0;
        int sell = 0;
        if (!bought)
        {
            int buyhere = -prices[index] + solve(1, index + 1, prices, dp);
            int notbuy = solve(0, index + 1, prices, dp);
            buy = max(buyhere, notbuy);
        }
        else
        {
            int sellhere = prices[index] + solve(0, index + 1, prices, dp);
            int notsell = solve(1, index + 1, prices, dp);
            sell = max(sellhere, notsell);
        }

        return dp[index][bought] = max(buy, sell);
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};

// tabulation method

class Solution
{
public:
    int solve(vector<int> &prices, vector<vector<int>> &dp)
    {

        int n = prices.size();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int bought = 0; bought < 2; bought++)
            {
                int buy = 0;
                int sell = 0;
                if (!bought)
                {
                    int buyhere = -prices[i] + dp[i + 1][1];
                    int notbuy = dp[i + 1][0];
                    buy = max(buyhere, notbuy);
                }
                else
                {
                    int sellhere = prices[i] + dp[i + 1][0];
                    int notsell = dp[i + 1][1];
                    sell = max(sellhere, notsell);
                }
                dp[i][bought] = max(sell, buy);
            }
        }

        return dp[0][0];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        return solve(prices, dp);
    }
};

// space optimisation method

class Solution
{
public:
    int solve(vector<int> &prices)
    {
        pair<int, int> curr;
        pair<int, int> prev = {0, 0};

        int n = prices.size();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int bought = 0; bought < 2; bought++)
            {
                int buy = 0;
                int sell = 0;
                if (!bought)
                {
                    int buyhere = -prices[i] + prev.second;
                    int notbuy = prev.first;
                    buy = max(buyhere, notbuy);
                    curr.first = buy;
                }
                else
                {
                    int sellhere = prices[i] + prev.first;
                    int notsell = prev.second;
                    sell = max(sellhere, notsell);
                    curr.second = sell;
                }
                prev = curr;
            }
        }

        return prev.first;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        return solve(prices);
    }
};