// S1 - Check all the matrix to find rotten and fresh + push rotten into queue
// S2 - Pair with all the directions
// S3 - DFS Traversal - each deapth add cnt++ & fresh-- with each fresh changed into rotten

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int cnt = 0, fresh = 0;
        queue<pair<int, int>> q;
        // S1
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        // S2
        vector<pair<int, int>> dr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (!fresh)
            return 0;
        // S3
        while (!q.empty())
        {
            int n = q.size();
            for (int k = 0; k < n; k++)
            {
                auto curr = q.front();
                int i = curr.first, j = curr.second;
                q.pop();

                for (auto d : dr)
                {
                    int x = d.first, y = d.second;
                    if (x + i < grid.size() && y + j < grid[i].size() && x + i >= 0 && y + j >= 0 && grid[x + i][y + j] == 1)
                    {
                        q.push({x + i, y + j});
                        grid[x + i][y + j] = 2;
                        fresh--;
                    }
                }
            }
            cnt++;
        }

        if (fresh)
            return -1;
        return (cnt) ? cnt - 1 : 0;
    }
};