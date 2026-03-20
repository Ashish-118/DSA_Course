class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> result;
        int n = grid.size(), m = grid[0].size();

        for (int row = 0; row < n; row++)
        {
            if (row + k - 1 >= n)
                continue;
            vector<int> ans;
            for (int col = 0; col < m; col++)
            {
                if (col + k - 1 >= m)
                    continue;
                int row2 = row + k - 1;
                int col2 = col + k - 1;

                set<int> st;

                for (int i = row; i <= row2; i++)
                {
                    for (int j = col; j <= col2; j++)
                    {
                        st.insert(grid[i][j]);
                    }
                }

                if (st.size() == 1)
                    ans.push_back(0);
                else
                {
                    int diff = INT_MAX;
                    int prev = INT_MIN;
                    for (auto x : st)
                    {
                        if (prev != INT_MIN)
                            diff = min(diff, abs(prev - x));
                        prev = x;
                    }
                    ans.push_back(diff);
                }
            }
            result.push_back(ans);
        }

        return result;
    }
};