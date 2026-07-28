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


// optimised by pruning the search space to first quadrant and using symmetry of the knight moves

class Solution
{
public:
    int minKnightMoves(int x, int y)
    {

        x = abs(x);
        y = abs(y);

        vector<pair<int, int>> dir = {
            {2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {-1, 2}, {-1, -2}};

        queue<vector<int>> q;
        q.push({0, 0, 0});

        set<pair<int, int>> st;
        st.insert({0, 0});

        while (!q.empty())
        {

            auto front = q.front();
            q.pop();

            int X = front[0];
            int Y = front[1];
            int steps = front[2];

            if (X == x && Y == y)
                return steps;

            for (auto &d : dir)
            {

                int x_ = X + d.first;
                int y_ = Y + d.second;

                if (x_ >= -2 &&
                    y_ >= -2 &&
                    x_ <= x + 2 &&
                    y_ <= y + 2 &&
                    st.find({x_, y_}) == st.end())
                {

                    st.insert({x_, y_});
                    q.push({x_, y_, steps + 1});
                }
            }
        }

        return -1;
    }
};

// using struct Node

class Solution
{
public:
    struct Node
    {
        int x;
        int y;
        int steps;
    };

    int minKnightMoves(int x, int y)
    {

        x = abs(x);
        y = abs(y);

        vector<pair<int, int>> dir = {
            {2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {-1, 2}, {-1, -2}};

        queue<Node> q;
        q.push({0, 0, 0});

        set<pair<int, int>> vis;
        vis.insert({0, 0});

        while (!q.empty())
        {

            Node cur = q.front();
            q.pop();

            if (cur.x == x && cur.y == y)
                return cur.steps;

            for (auto &d : dir)
            {

                int nx = cur.x + d.first;
                int ny = cur.y + d.second;

                if (nx >= -2 &&
                    ny >= -2 &&
                    nx <= x + 2 &&
                    ny <= y + 2 &&
                    vis.find({nx, ny}) == vis.end())
                {

                    vis.insert({nx, ny});
                    q.push({nx, ny, cur.steps + 1});
                }
            }
        }

        return -1;
    }
};