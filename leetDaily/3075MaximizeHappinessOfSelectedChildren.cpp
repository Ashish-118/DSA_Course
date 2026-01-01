class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int subtract = 0;
        sort(begin(happiness), end(happiness), greater<int>());
        long long ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans += max(0, happiness[i] - subtract);
            subtract++;
        }

        return ans;
    }
};