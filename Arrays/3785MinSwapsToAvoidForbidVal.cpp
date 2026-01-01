class Solution
{
public:
    int minSwaps(vector<int> &nums, vector<int> &forbidden)
    {

        int n = nums.size();

        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }

        for (int i : forbidden)
        {
            mp[i]++;
        }

        for (auto i : mp)
        {
            if (i.second > n)
            {
                return -1;
            }
        }

        map<int, int> bad;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == forbidden[i])
            {
                bad[nums[i]]++;
                total++;
            }
        }

        int maxi = 0;

        for (auto i : bad)
        {
            maxi = max(maxi, i.second);
        }

        return max((total + 1) / 2, maxi);
    }
};