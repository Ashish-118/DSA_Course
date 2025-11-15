class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        int ans = 0;
        int sum1 = 0;

        for (int i = 0; i < n; i++)
        {
            sum1 += nums[i];

            if (nums[i] != 0)
                continue;

            if (abs(sum - 2 * sum1) == 0)
            {
                ans += 2;
            }
            else if (abs(sum - 2 * sum1) == 1)
            {
                ans += 1;
            }
        }

        return ans;
    }
};