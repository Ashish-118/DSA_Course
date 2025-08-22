class Solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();

        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxReach >= n - 1)
                return 1;

            maxReach = max(maxReach, i + nums[i]);
            if (maxReach == i)
                return 0;
        }
        return 0;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        return solve(nums);
    }
};