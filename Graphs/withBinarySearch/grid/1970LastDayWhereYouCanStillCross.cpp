class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {

        int day = 0;
        int n = cells.size();
        vector<vector<int>> grid;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int l = 0, r = n - 1;
        vector<bool> visited;

        auto valid = [&](int x, int y)
        {
            return x >= 0 && y >= 0 && x < row && y < col &&
                   !visited[col * x + y] && grid[x][y] == 0;
        };

        auto poss = [&](int mid)
        {
            grid = vector<vector<int>>(row, vector<int>(col, 0));
            visited = vector<bool>(n + 1, false);

            for (int i = 0; i <= mid; i++)
            {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            queue<pair<int, int>> q;
            for (int c = 0; c < col; c++)
            {
                if (grid[0][c] == 0)
                {
                    q.push({0, c});
                    visited[c] = true;
                }
            }

            while (!q.empty())
            {
                auto front = q.front();
                int r = front.first;
                int c = front.second;
                q.pop();

                if (r + 1 == row)
                    return true;

                for (auto d : dir)
                {
                    int r_ = r + d.first;
                    int c_ = c + d.second;
                    if (valid(r_, c_))
                    {
                        q.push({r_, c_});
                        visited[col * r_ + c_] = true;
                    }
                }
            }

            return false;
        };

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (poss(mid))
            {
                day = max(day, mid + 1);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return day;
    }
}; // time complexity: O(row * col * log(n))