class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = maze.size(), m = maze[0].size();
        map<pair<int, int>, bool> visited;

        while (!q.empty())
        {
            auto front = q.front();

            auto nodeLoc = front.first;
            int lvl = front.second;
            q.pop();
            if ((entrance[0] != nodeLoc.first || entrance[1] != nodeLoc.second) && (nodeLoc.first == n - 1 || nodeLoc.first == 0 || nodeLoc.second == 0 || nodeLoc.second == m - 1))
                return lvl;
            for (auto &d : dir)
            {
                int newX = nodeLoc.first + d.first;
                int newY = nodeLoc.second + d.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] != '+' && !visited[{newX, newY}])
                {
                    q.push({{newX, newY}, lvl + 1});
                    visited[{newX, newY}] = true;
                }
            }
        }

        return -1;
    }
};

//. more optimal code

//  is to turn the visited cells into walls by changing their value to '+'. This way, we don't need a separate visited map, and we can directly check if a cell is a wall or has been visited by checking its value in the maze.

// Simply Use BFS :
// Time  - O(m*n)
// Space - O(m+n)
class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // marking it visited
        int steps = 0;

        while (!que.empty())
        {
            int size = que.size();

            while (size--)
            {
                pair<int, int> temp = que.front();
                que.pop();

                if (temp != make_pair(entrance[0], entrance[1]) &&
                    (temp.first == 0 || temp.first == m - 1 || temp.second == 0 || temp.second == n - 1))
                    return steps;

                for (auto &dir : directions)
                {
                    int i = temp.first + dir[0];
                    int j = temp.second + dir[1];

                    if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '+')
                    {
                        que.push({i, j});
                        maze[i][j] = '+'; // marking it as visited
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};