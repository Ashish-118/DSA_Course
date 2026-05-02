class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        map<int, int> mp;

        for (auto x : nums)
        {
            mp[-x]++;
        }

        int ans = 0;
        int prev = 0;

        for (auto m : mp)
        {
            prev += m.second;

            mp.erase(m.first);
            if (!mp.empty())
            {
                ans += prev;
            }
        }
        return ans;
    }
};