#define mod 1000000007

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pow2(n, 1);

        for (int i = 1; i < n; ++i)
        {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        int res = 0;
        int left = 0, right = n - 1;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                res = (res + pow2[right - left]) % mod;
                left++;
            }
            else
            {
                right--;
            }
        }

        return res;
    }
};
