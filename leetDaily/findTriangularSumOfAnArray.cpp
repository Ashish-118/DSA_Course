class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                nums[j] = (nums[j] + nums[j + 1]) % 10;
            }
        }

        return nums[0];
    }
};