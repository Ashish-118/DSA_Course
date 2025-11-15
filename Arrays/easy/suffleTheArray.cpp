class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans(2 * n, 0);
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            ans[index++] = nums[i];
            ans[index++] = nums[i + (n)];
        }
        return ans;
    }
};