boiler class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i] = (nums[i] + (i > 0 ? prefix[i - 1] : 0)) % k;
        }

        for (int i = 0; i < n; i++)
        {
            if ((prefix[i] == 0 && i > 0) ||
                (mp.count(prefix[i]) && i - mp[prefix[i]] >= 2))
            {

                return true;
            }
            else
            {
                if (mp.count(prefix[i]) == 0)
                    mp[prefix[i]] = i;
            }
        }

        return false;
    }
};