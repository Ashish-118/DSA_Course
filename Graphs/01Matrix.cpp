class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            for (auto [dx, dy] : directions)
            {
                int ni = i + dx;
                int nj = j + dy;

                if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                {

                    if (dist[ni][nj] > dist[i][j] + 1)
                    {
                        dist[ni][nj] = dist[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return dist;
    }
};
