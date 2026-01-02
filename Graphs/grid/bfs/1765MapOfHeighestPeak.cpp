class Solution
{
public:
    using p = pair<int, int>;
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<vector<int>> height(m, vector<int>(n, 0));
        queue<p> q;

        auto valid = [&](int i, int j)
        {
            return i >= 0 && j >= 0 && i < m && !visited[i][j] && j < n;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    height[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int len = q.size();
            for (int k = 0; k < len; k++)
            {
                auto [i, j] = q.front();
                q.pop();

                for (auto [x, y] : dir)
                {
                    int i_ = i + x;
                    int j_ = j + y;

                    if (valid(i_, j_))
                    {
                        visited[i_][j_] = true;
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_, j_});
                    }
                }
            }
        }

        return height;
    }
};