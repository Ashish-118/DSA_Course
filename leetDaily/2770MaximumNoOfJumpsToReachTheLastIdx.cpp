class Solution
{
public:
    int t[1000];
    int solve(int i, vector<int> &nums, int target)
    {
        if (i == nums.size() - 1)
            return 0;

        if (t[i] != -1)
            return t[i];

        int ans = INT_MIN;

        for (int k = i + 1; k < nums.size(); k++)
        {
            if (abs(nums[i] - nums[k]) <= target)
            {
                int ret = solve(k, nums, target);
                if (ret != INT_MIN)
                {
                    ans = max(ans, 1 + ret);
                }
            }
        }

        return t[i] = ans;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        memset(t, -1, sizeof(t));
        int ret = solve(0, nums, target);
        return (ret == INT_MIN ? -1 : ret);
    }
};