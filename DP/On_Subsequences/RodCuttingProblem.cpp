// User function Template for C++

class Solution
{
public:
    int Tab(vector<int> &val, int length)
    {
        int n = val.size();
        vector<int> prev(length + 1, 0), dp(length + 1, 0);

        for (int i = length; i >= 1; i--)
        {
            for (int c = 0; c <= length; c++)
            {
                int take = 0;
                if (i <= c)
                {
                    take = val[i - 1] + dp[c - i];
                }
                int skip = prev[c];
                dp[c] = max(take, skip);
            }
            prev = dp;
        }

        return prev[length];
    }
    int cutRod(vector<int> &price)
    {

        return Tab(price, price.size());
    }
};