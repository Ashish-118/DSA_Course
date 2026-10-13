class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            nums[i] = abs(nums[i]);
        }

        sort(begin(nums), end(nums));

        long long ans = 0;

        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            ans += nums[n - i] * nums[n - i];
        }

        for (int i = 0; i < n / 2; i++)
        {
            ans -= nums[i] * nums[i];
        }

        return ans;
    }
};