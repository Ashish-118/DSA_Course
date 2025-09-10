class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        int n = graph.size();
        queue<vector<int>> q;
        q.push({0});

        while (!q.empty())
        {
            auto front = q.front();
            int node = front.back();
            q.pop();
            if (node == n - 1)
            {
                ans.push_back(front);
                continue;
            }
            for (auto &ngb : graph[node])
            {
                front.push_back(ngb);
                q.push(front);
                front.pop_back();
            }
        }
        return ans;
    }
};