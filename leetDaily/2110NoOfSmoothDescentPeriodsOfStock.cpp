class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = prices.size();
        long long ans = n;

        int left = 0;
        int prev = 0;

        for (int right = 0; right < n; right++)
        {

            if ((prev - prices[right]) == 1)
            {

                ans += ((right - left + 1) - 1);
            }
            else
            {
                left = right;
            }

            prev = prices[right];
        }

        return ans;
    }
};