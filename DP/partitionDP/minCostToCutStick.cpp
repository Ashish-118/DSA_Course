// recurrsion + memoization
class Solution
{
public:
    map<pair<int, int>, int> mp;
    int solve(int i, int j, vector<int> &cuts)
    {
        bool check = false;
        int mini = INT_MAX;
        if (mp.count({i, j}))
            return mp[{i, j}];
        for (auto x : cuts)
        {
            if (i < x && x < j)
            {
                check = true;
                mini = min(mini, solve(i, x, cuts) + solve(x, j, cuts));
            }
        }

        return mp[{i, j}] = (check ? mini + j - i : 0);
    }
    int minCost(int n, vector<int> &cuts) { return solve(0, n, cuts); }
};