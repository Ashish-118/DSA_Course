class Solution
{
public:
    int minKnightMoves(int x, int y)
    {
        vector<pair<int, int>> dir = {{2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {-1, 2}, {-1, -2}};

        queue<vector<int>> q;
        q.push({0, 0, 0});
        set<pair<int, int>> st;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int X = front[0], Y = front[1], steps = front[2];

            if (X == x && Y == y)
            {
                return steps;
            }

            for (auto &d : dir)
            {
                int x_ = X + d.first, y_ = Y + d.second;
                if (st.find({x_, y_}) == st.end())
                {
                    q.push({x_, y_, steps + 1});
                    st.insert({x_, y_});
                }
            }
        }

        return -1;
    }
};