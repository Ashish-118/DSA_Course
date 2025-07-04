class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int times = nums.size() / 2;
        int ans = -1;
        for (auto x : m)
        {
            if (x.second > times)
            {
                ans = x.first;
            }
        }
        return ans;
    }
};