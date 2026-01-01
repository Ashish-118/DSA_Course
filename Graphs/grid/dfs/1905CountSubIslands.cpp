class Solution
{
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool valid(int i, int j, vector<vector<int>> &grid2)
    {
        return i >= 0 && j >= 0 && i < grid2.size() && !visited[i][j] &&
               j < grid2[0].size() && grid2[i][j] == 1;
    }

    bool solve(int i, int j, vector<vector<int>> &grid1,
               vector<vector<int>> &grid2)
    {

        visited[i][j] = true;

        bool ans = (grid1[i][j] == 1);
        for (auto d : dir)
        {
            int i_ = i + d.first;
            int j_ = j + d.second;

            if (valid(i_, j_, grid2))
            {
                ans &= solve(i_, j_, grid1, grid2);
            }
        }

        return ans;
    }
    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        int m = grid2.size(), n = grid2[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && valid(i, j, grid2))
                {
                    cout << i << j << endl;
                    if (solve(i, j, grid1, grid2))
                    {
                        cout << "yes" << endl;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};