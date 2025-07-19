class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited, int m, int n)
    {
        if (board[i][j] != 'O')
        {
            return;
        }
        visited[i][j] = true;
        board[i][j] = '#';
        if ((i - 1) >= 0 && !visited[i - 1][j])
            dfs(i - 1, j, board, visited, m, n);
        if ((j - 1) >= 0 && !visited[i][j - 1])
            dfs(i, j - 1, board, visited, m, n);
        if ((i + 1) < m && !visited[i + 1][j])
            dfs(i + 1, j, board, visited, m, n);
        if ((j + 1) < n && !visited[i][j + 1])
            dfs(i, j + 1, board, visited, m, n);
    }

    void solve(vector<vector<char>> &board)
    {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O' && (i == 0 || j == 0 || i == (m - 1) || j == (n - 1)))
                {
                    dfs(i, j, board, visited, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};