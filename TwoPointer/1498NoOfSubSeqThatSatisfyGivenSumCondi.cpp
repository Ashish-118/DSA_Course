#define mod 1000000007
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> powerOf2(n);
        powerOf2[0] = 1;

        for (int i = 1; i < n; i++)
        {
            powerOf2[i] = (powerOf2[i - 1] * 2) % mod;
        }

        while (l <= r)
        {
            if ((nums[l] + nums[r]) <= target)
            {
                ans = (ans + powerOf2[r - l]) % mod;
                l++;
            }
            else
                r--;
        }

        return ans;
    }
};