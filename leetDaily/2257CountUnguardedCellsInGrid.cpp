class Solution
{
public:
    vector<vector<int>> visited;

    void solve(int m, int n, int x, int y)
    {

        // right

        for (int j = y + 1; j < n; j++)
        {

            if (visited[x][j] == 2)
                break;
            visited[x][j] = 1;
        }

        // left

        for (int j = y - 1; j >= 0; j--)
        {

            if (visited[x][j] == 2)
                break;
            visited[x][j] = 1;
        }

        // up

        for (int i = x - 1; i >= 0; i--)
        {

            if (visited[i][y] == 2)
                break;
            visited[i][y] = 1;
        }
        // down
        for (int i = x + 1; i < m; i++)
        {

            if (visited[i][y] == 2)
                break;
            visited[i][y] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {

        visited.assign(m, vector<int>(n, 0));

        for (auto &x : walls)
        {
            visited[x[0]][x[1]] = 2;
        }
        for (auto &x : guards)
        {
            visited[x[0]][x[1]] = 2;
        }

        for (auto g : guards)
        {

            solve(m, n, g[0], g[1]);
        }

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                    ans++;
            }
        }

        return ans;
    }
};