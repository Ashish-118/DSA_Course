class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void bfs(vector<vector<int>> &heights, vector<vector<int>> &vis, queue<pair<int, int>> &q)
    {
        int m = heights.size(), n = heights[0].size();
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x1 = x + dir[i][0], y1 = y + dir[i][1]; // neigh
                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !vis[x1][y1] && heights[x][y] <= heights[x1][y1])
                {
                    q.push({x1, y1});
                    vis[x1][y1] = 1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visP(m, vector<int>(n, 0));
        vector<vector<int>> visA(m, vector<int>(n, 0));
        queue<pair<int, int>> q1, q2;
        // pushing all boundary elemens into respective queues for BFS and marking as vis
        for (int i = 0; i < m; i++)
        {
            visP[i][0] = 1;
            q1.push({i, 0});
        }
        for (int j = 0; j < n; j++)
        {
            visP[0][j] = 1;
            q1.push({0, j});
        }
        for (int i = 0; i < m; i++)
        {
            visA[i][n - 1] = 1;
            q2.push({i, n - 1});
        }
        for (int j = 0; j < n; j++)
        {
            visA[m - 1][j] = 1;
            q2.push({m - 1, j});
        }
        // search for neighbouring cells and fill the visited arrays
        bfs(heights, visP, q1);
        bfs(heights, visA, q2);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visP[i][j] && visA[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};