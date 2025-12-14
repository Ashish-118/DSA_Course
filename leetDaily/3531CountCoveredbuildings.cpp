class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        unordered_map<int, set<int>> X;
        unordered_map<int, set<int>> Y;

        for (auto m : buildings)
        {
            X[m[0]].insert(m[1]);
            Y[m[1]].insert(m[0]);
        }

        int ans = 0;

        for (int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];

            // for vertical
            auto top = X[x].upper_bound(y);
            if (top == X[x].end())
                continue;
            auto bottom = X[x].lower_bound(y);
            if (bottom == X[x].begin())
                continue;
            // for horizontal

            auto left = Y[y].lower_bound(x);
            if (left == Y[y].begin())
                continue;
            auto right = Y[y].upper_bound(x);
            if (right == Y[y].end())
                continue;

            ans++;
        }
        return ans;
    }
};
// time complexity: O(nlogn)