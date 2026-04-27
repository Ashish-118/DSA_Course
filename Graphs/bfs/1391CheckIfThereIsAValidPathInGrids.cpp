class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    vector<pair<int, int>> possDir = {{2, 1}, {3, 0}, {2, 0}, {0, 1}, {2, 3}, {3, 1}};
    vector<vector<bool>> visited;

    bool solve(int i, int j, pair<int, int> parent, vector<vector<int>> &grid)
    {
        visited[i][j] = true;

        auto d = possDir[grid[i][j] - 1];
        auto dir1 = dir[d.first];
        auto dir2 = dir[d.second];
        int x1_ = i + dir1.first, y1_ = j + dir1.second;
        int x2_ = i + dir2.first, y2_ = j + dir2.second;

        if (parent != make_pair(-1, -1) && parent != make_pair(x1_, y1_) &&
            parent != make_pair(x2_, y2_))
        {
            visited[i][j] = false;
            return false;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return true;

        if (parent != make_pair(x1_, y1_) && x1_ >= 0 && y1_ >= 0 &&
            x1_ < grid.size() && y1_ < grid[0].size() && !visited[x1_][y1_])
        {
            if (solve(x1_, y1_, {i, j}, grid))
                return true;
        }

        if (parent != make_pair(x2_, y2_) && x2_ >= 0 && y2_ >= 0 &&
            x2_ < grid.size() && y2_ < grid[0].size() && !visited[x2_][y2_])
        {
            if (solve(x2_, y2_, {i, j}, grid))
                return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));

        return solve(0, 0, {-1, -1}, grid);
    }
};