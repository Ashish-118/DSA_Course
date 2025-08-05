class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int ans = -200;
        set<int> s;
        for (auto x : nums)
        {
            s.insert(x);
        }

        for (auto i : s)
        {
            ans = max({ans, ans + i, i});
        }
        return ans;
    }
};