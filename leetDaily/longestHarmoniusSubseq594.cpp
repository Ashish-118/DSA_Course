class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int maxi = 0;

        for (auto x : m)
        {
            if (m.find(x.first + 1) != m.end())
            {
                maxi = max(maxi, m[x.first] + m[x.first + 1]);
            }
        }
        return maxi;
    }
};