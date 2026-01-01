class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();

        int cum_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        int l = 0;

        for (int i = 0; i < n; i++)
        {
            cum_sum += nums[i];

            int to_sub = cum_sum - k;

            if (mp.count(to_sub) != 0)
            {

                count += mp[to_sub];
            }

            mp[cum_sum]++;
        }

        return count;
    }
};