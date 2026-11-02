class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        int median = n / 2;
        sort(begin(nums), end(nums));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (median != i)
            {
                ans += abs(nums[median] - nums[i]);
            }
        }

        return ans;
    }
};