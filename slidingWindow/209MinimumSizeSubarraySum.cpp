class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int l = 0;
        int windowSum = 0;
        int minSize = INT_MAX;
        int n = nums.size();

        for (int r = 0; r < n; r++)
        {
            windowSum += nums[r];
            while (l < n && windowSum >= target)
            {
                windowSum -= nums[l];
                minSize = min(minSize, r - l + 1);
                l++;
            }
        }
        return minSize != INT_MAX ? minSize : 0;
    }
};