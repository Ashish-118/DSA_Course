class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        int prefix = 1, suffix = 1;
        int maxSub = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                maxSub = max(maxSub, nums[i]);
                prefix = 1;
            }
            else
            {
                prefix *= nums[i];
                maxSub = max(maxSub, prefix);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                maxSub = max(maxSub, nums[i]);
                suffix = 1;
            }
            else
            {
                suffix *= nums[i];
                maxSub = max(maxSub, suffix);
            }
        }

        return maxSub;
    }
};