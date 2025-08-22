class Solution
{
public:
    int solve(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 0; limit < k; limit++)
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
                        if (limit + 1 <= k)
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

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        return solve(prices, k);
    }
};
//  the space optimised solution