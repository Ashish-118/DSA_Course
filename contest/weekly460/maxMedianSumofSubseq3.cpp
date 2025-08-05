class Solution
{
public:
    long long maximumMedianSum(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        bool toggle = false;
        int req = n / 3;
        int j = n - 1;
        long long ans = 0;
        sort(nums.begin(), nums.end());
        while (count < req)
        {
            if (toggle)
            {
                count++;
                ans += nums[j];
            }

            toggle = !toggle;
            j--;
        }

        return ans;
    }
};
©leetcode