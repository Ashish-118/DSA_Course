class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int div = nums[i] / 3;
            ans += min((div + 1) * 3 - nums[i], nums[i] - div * 3);
        }
        return ans;
    }
};