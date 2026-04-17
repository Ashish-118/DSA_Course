class Solution
{
public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        int ans = INT_MAX;
        unordered_map<string, int> mp;

        int n = nums.size();

        for (int i = n - 1; i >= 0; i--)
        {
            string str = to_string(nums[i]);
            reverse(begin(str), end(str));

            while (str[0] == '0')
            {
                str = str.substr(1);
            }

            if (mp.count(str))
            {
                ans = min(ans, mp[str] - i);
            }

            mp[to_string(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};