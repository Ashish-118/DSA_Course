class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));

        vector<vector<int>> ans;
        ans.push_back({-1, -1});
        for (auto x : intervals)
        {
            auto back = ans.back();
            if (back[1] < x[0])
            {
                ans.push_back({x[0], x[1]});
            }
            else
            {
                ans.back()[1] = max(back[1], x[1]);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};