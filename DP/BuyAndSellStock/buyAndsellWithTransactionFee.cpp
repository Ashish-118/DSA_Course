class Solution
{
public:
    int solve(vector<int> &prices, int fee)
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
                    int buyhere = -prices[i] - fee + prev.second;
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
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        return solve(prices, fee);
    }
};