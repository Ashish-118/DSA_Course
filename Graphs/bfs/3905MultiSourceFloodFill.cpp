class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources)
    {

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> grid(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        for (auto s : sources)
        {
            grid[s[0]][s[1]] = s[2];
            visited[s[0]][s[1]] = true;
            q.push({s[0], s[1]});
        }

        while (!q.empty())
        {
            int len = q.size();
            set<pair<int, int>> st;

            for (int i = 0; i < len; i++)
            {
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for (auto d : dir)
                {
                    int x_ = x + d.first;
                    int y_ = y + d.second;
                    if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && !visited[x_][y_])
                    {
                        st.insert({x_, y_});
                        grid[x_][y_] = max(grid[x_][y_], grid[x][y]);
                    }
                }
            }

            for (auto s : st)
            {
                visited[s.first][s.second] = true;
                q.push({s.first, s.second});
            }
        }

        return grid;
    }
};