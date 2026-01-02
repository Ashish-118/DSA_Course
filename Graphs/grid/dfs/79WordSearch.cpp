class Solution
{
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(int i, int j, int idx,
             vector<vector<char>> &board,
             string &word)
    {

        // matched full word
        if (idx == word.size())
            return true;

        // bounds / mismatch / reuse check
        if (i < 0 || j < 0 || i >= n || j >= m ||
            visited[i][j] ||
            board[i][j] != word[idx])
        {
            return false;
        }

        visited[i][j] = true;

        for (auto [dx, dy] : dir)
        {
            if (dfs(i + dx, j + dy, idx + 1, board, word))
                return true;
        }

        visited[i][j] = false; // backtrack
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};
