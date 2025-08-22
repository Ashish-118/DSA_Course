class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        // Code here
        int minCost = 0;
        sort(begin(prices), end(prices));
        int bought = 0;
        for (int i = 0; i < prices.size() && bought < prices.size(); i++)
        {
            minCost += prices[i];
            bought += (k + 1);
        }
        bought = 0;
        int maxCost = 0;

        for (int i = prices.size() - 1; i >= 0 && bought < prices.size(); i--)
        {
            maxCost += prices[i];
            bought += (k + 1);
        }

        return {minCost, maxCost};
    }
};