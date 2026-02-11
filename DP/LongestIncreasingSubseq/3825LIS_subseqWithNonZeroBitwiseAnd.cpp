class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int ans = 0, n = nums.size();

        for (int i = 0; i < 32; i++)
        {

            vector<int> lis;

            for (int j = 0; j < n; j++)
            {
                int bit = nums[j] & (1 << i);
                if (bit == 0)
                    continue;

                if (lis.empty() || lis.back() < nums[j])
                {
                    lis.push_back(nums[j]);
                }
                else
                {
                    auto idx = lower_bound(begin(lis), end(lis), nums[j]) -
                               lis.begin();
                    lis[idx] = nums[j];
                }
            }
            int len = lis.size();
            ans = max(ans, len);
        }

        return ans;
    }
};

// time complexity: O(32 * n log n) => O(n log n)
// space complexity: O(n) for the lis vector