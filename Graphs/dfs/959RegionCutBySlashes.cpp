class Solution
{
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, vector<vector<int>> &matrix, int n, int m)
    {
        visited[i][j] = true;

        for (auto d : dir)
        {
            int i_ = i + d.first;
            int j_ = j + d.second;

            if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && matrix[i_][j_] == 0 &&
                !visited[i_][j_])
            {

                dfs(i_, j_, matrix, n, m);
            }
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        int row = grid.size() * 3;
        int col = grid[0].size() * 3;

        vector<vector<int>> matrix(row, vector<int>(col, 0));
        int r = 0;
        for (int i = 0; i < row / 3; i++)
        {
            int c = 0;
            for (int j = 0; j < col / 3; j++)
            {

                int y = r;
                if (grid[i][j] == '/')
                {
                    int x = c + 2;
                    for (int k = 0; k < 3; k++)
                    {
                        matrix[y++][x--] = 1;
                    }
                }
                else if (grid[i][j] == '\\')
                {
                    int x = c;
                    for (int k = 0; k < 3; k++)
                    {
                        matrix[y++][x++] = 1;
                    }
                }

                c = c + 3;
            }
            r = r + 3;
        }

        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        int count = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0 && !visited[i][j])
                {
                    dfs(i, j, matrix, row, col);
                    count++;
                }
            }
        }

        return count;
    }
};