class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int n = nums.size();

        int MaxAbsSum = 0;
        int minCurrSub = 0;
        int maxCurrSub = 0;

        for (int i = 0; i < n; i++)
        {
            maxCurrSub = max(maxCurrSub + nums[i], nums[i]);
            MaxAbsSum = max(MaxAbsSum, abs(maxCurrSub));
        }

        for (int i = 0; i < n; i++)
        {
            minCurrSub = min(minCurrSub + nums[i], nums[i]);
            MaxAbsSum = max(MaxAbsSum, abs(minCurrSub));
        }

        return MaxAbsSum;
    }
};

// time complexity: O(n) // space complexity: O(1)