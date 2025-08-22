//  recurrsion with memoization

class Solution
{
public:
    int solve(int buy, int index, vector<int> &prices, int limit,
              vector<vector<vector<int>>> &dp)
    {
        if (index >= prices.size() || limit >= 2)
            return 0;
        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        int buying = 0, sell = 0;
        if (buy)
        {
            int bought = -prices[index] + solve(0, index + 1, prices, limit, dp);
            int notBought = 0 + solve(1, index + 1, prices, limit, dp);
            buying = max(bought, notBought);
        }
        else
        {
            int sold = prices[index] + solve(1, index + 1, prices, limit + 1, dp);
            int notSold = 0 + solve(0, index + 1, prices, limit, dp);
            sell = max(sold, notSold);
        }

        return dp[index][buy][limit] = max(buying, sell);
    }
    int maxProfit(vector<int> &prices)
    {
        int limit = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(1, 0, prices, limit, dp);
    }
};

// bottom up / tabulation method

class Solution
{
public:
    int solve(vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 0; limit < 2; limit++)
                {
                    int profit = 0;

                    if (buy)
                    {
                        int bought = -prices[i] + dp[i + 1][0][limit];
                        int notBought = 0 + dp[i + 1][1][limit];
                        profit = max(bought, notBought);
                    }
                    else
                    {
                        int sold = 0;
                        if (limit + 1 <= 2)
                        {
                            sold = prices[i] + dp[i + 1][1][limit + 1];
                        }
                        int notSold = 0 + dp[i + 1][0][limit];
                        profit = max(sold, notSold);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][0];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        return solve(prices, dp);
    }
};

///.  here is the space optimization method

class Solution
{
public:
    int solve(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 0; limit < 2; limit++)
                {
                    int profit = 0;

                    if (buy)
                    {
                        int bought = -prices[i] + next[0][limit];
                        int notBought = 0 + next[1][limit];
                        profit = max(bought, notBought);
                    }
                    else
                    {
                        int sold = 0;
                        if (limit + 1 <= 2)
                        {
                            sold = prices[i] + next[1][limit + 1];
                        }
                        int notSold = 0 + next[0][limit];
                        profit = max(sold, notSold);
                    }

                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][0];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        return solve(prices);
    }
};
