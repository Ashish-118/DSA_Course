class Solution
{
public:
    int mod = 1000000007;
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        for (auto query : queries)
        {
            for (int i = query[0]; i <= query[1]; i += query[2])
            {
                nums[i] = (1LL * nums[i] * query[3]) % mod;
            }
        }

        int ans = 0;

        for (auto x : nums)
            ans ^= x;

        return ans;
    }
};