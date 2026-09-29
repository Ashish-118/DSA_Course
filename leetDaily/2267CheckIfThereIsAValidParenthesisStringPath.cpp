class Solution
{
public:
    int t[101][101][1001];
    int n, m;
    bool solve(int i, int j, int track, vector<vector<char>> &grid)
    {
        if (i >= n || j >= m)
        {
            return false;
        }
        else if (track == 0 && grid[i][j] == ')')
        {
            return t[i][j][track] = false;
        }
        else if (i == n - 1 && j == m - 1)
        {
            track += (grid[i][j] == '(' ? 1 : -1);
            if (track == 0)
            {
                return true;
            }
            return false;
        }

        track += (grid[i][j] == '(' ? 1 : -1);
        if (t[i][j][track] != -1)
        {
            return t[i][j][track];
        }

        for (auto d : vector<pair<int, int>>{{1, 0}, {0, 1}})
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            bool get = solve(x_, y_, track, grid);
            if (get)
            {
                return t[i][j][track] = true;
            }
        }

        return t[i][j][track] = false;
    }

    bool hasValidPath(vector<vector<char>> &grid)
    {
        memset(t, -1, sizeof(t));
        n = grid.size();
        m = grid[0].size();
        return solve(0, 0, 0, grid);


    }
};