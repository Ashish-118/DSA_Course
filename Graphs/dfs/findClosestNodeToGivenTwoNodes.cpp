class Solution
{
public:
    void dfs(int node, vector<int> &edges, vector<int> &dist, int count, vector<bool> &visited)
    {
        visited[node] = true;
        dist[node] = count;
        if (edges[node] != -1 and !visited[edges[node]])
        {
            dfs(edges[node], edges, dist, count + 1, visited);
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        vector<bool> visited(n, false);

        dfs(node1, edges, dist1, 0, visited);
        fill(begin(visited), end(visited), false);
        dfs(node2, edges, dist2, 0, visited);

        int minVal = INT_MAX;
        int ansNode = -1;

        for (int i = 0; i < n; i++)
        {
            int num = max(dist1[i], dist2[i]);

            if (num < minVal)
            {
                minVal = num;
                ansNode = i;
            }
            else if (num == minVal)
            {
                ansNode = min(ansNode, i);
            }
        }

        return ansNode;
    }
};