class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &board, vector<vector<bool>> &visited, int m, int n)
    {
        if (board[i][j] != 1)
        {
            return;
        }
        visited[i][j] = true;
        board[i][j] = -1;
        if ((i - 1) >= 0 && !visited[i - 1][j])
            dfs(i - 1, j, board, visited, m, n);
        if ((j - 1) >= 0 && !visited[i][j - 1])
            dfs(i, j - 1, board, visited, m, n);
        if ((i + 1) < m && !visited[i + 1][j])
            dfs(i + 1, j, board, visited, m, n);
        if ((j + 1) < n && !visited[i][j + 1])
            dfs(i, j + 1, board, visited, m, n);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1 && (i == 0 || j == 0 || i == (m - 1) || j == (n - 1)))
                {
                    dfs(i, j, grid, visited, m, n);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};