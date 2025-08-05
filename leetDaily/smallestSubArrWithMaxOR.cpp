class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> last(32, -1); // Last position where each bit was seen
        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; --i)
        {
            for (int bit = 0; bit < 32; ++bit)
            {
                if ((nums[i] >> bit) & 1)
                {
                    last[bit] = i;
                }
            }

            int maxReach = i;
            for (int bit = 0; bit < 32; ++bit)
            {
                if (last[bit] != -1)
                {
                    maxReach = max(maxReach, last[bit]);
                }
            }

            ans[i] = maxReach - i + 1;
        }

        return ans;
    }
};
