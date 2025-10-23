class Solution
{
public:
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool dfs(int i, int j, vector<vector<bool>> &visited,
             vector<vector<int>> &grid, int t)
    {
        visited[i][j] = true;

        if (i == grid.size() - 1 && j == grid.size() - 1)
            return true;

        for (auto &d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid.size() &&
                !visited[x_][y_] && grid[x_][y_] <= t)
            {

                if (dfs(x_, y_, visited, grid, t))
                    return true;
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int low = 0, high = 2500;
        int n = grid.size();
        int ans = -1;

        vector<vector<bool>> visited(
            n, vector<bool>(n, false)); // ✅ initialize here

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            visited.assign(
                n, vector<bool>(n, false)); // reset for each iteration ✅

            if (grid[0][0] <= mid && dfs(0, 0, visited, grid, mid))
            {
                cout << "mid " << mid << endl;
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};