class Solution
{
public:
    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n) && (y >= 0 && y < m);
    }
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int k, int r, int c, vector<pair<int, int>> &dr, int n, int m)
    {

        visited[r][c] = true;
        long long sum = grid[r][c];
        for (auto &dir : dr)
        {
            int x = dir.first + r;
            int y = dir.second + c;

            if (isValid(x, y, n, m) && !visited[x][y] && grid[x][y] != 0)
            {
                sum += dfs(grid, visited, k, x, y, dr, n, m);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] != 0)
                {
                    int val = dfs(grid, visited, k, i, j, dir, n, m);
                    count += (val % k == 0 ? 1 : 0);
                }
            }
        }
        return count;
    }
};
©leetcode