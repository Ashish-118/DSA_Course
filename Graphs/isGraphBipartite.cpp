// bfs

class Solution
{
public:
    bool solve(vector<vector<int>> &graph, int node, vector<int> &color)
    {
        queue<pair<int, int>> q;
        q.push({node, 0}); // node,colorType

        int n = graph.size();

        while (!q.empty())
        {
            auto front = q.front();
            int node = front.first;
            int colorType = front.second;
            q.pop();
            for (auto &x : graph[node])
            {
                if (color[x] == -1)
                {
                    color[x] = !colorType;
                    q.push({x, !colorType});
                }
                else
                {
                    if (colorType == color[x])
                        return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> color(n, -1);

        bool check = true;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                check = check && solve(graph, i, color);
            }
        }

        return check;
    }
};