class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = n - 1; i >= 1; i--)
        {
            int t = ceil((double)nums[i] / k);
            int index = lower_bound(begin(nums), end(nums), t) - nums.begin();
            if (index < i)
            {
                ans = min(index + (n - 1 - i), ans);
            }
        }
        return ans == INT_MAX ? n - 1 : ans;
    }
};
©leetcode