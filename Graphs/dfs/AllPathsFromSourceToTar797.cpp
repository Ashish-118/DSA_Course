class Solution
{
public:
    vector<vector<int>> allpaths;
    void dfs(int src, int dest, vector<int> &path, vector<vector<int>> &graph)
    {
        path.push_back(src);
        if (src == dest)
        {
            allpaths.push_back(path);
        }
        for (auto neighbor : graph[src])
        {
            dfs(neighbor, dest, path, graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        // adjacency list is given
        int n = graph.size() - 1;
        allpaths.resize(0);
        vector<int> path;
        dfs(0, n, path, graph);
        return allpaths;
    }
};