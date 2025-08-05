class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {

        vector<int> dist(V, INT_MAX);
        vector<int> visited(V, false);
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &x : edges)
        {
            int u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        set<pair<int, int>> st;
        dist[0] = 0;
        st.insert({0, 0});

        while (!st.empty())
        {
            auto top = *st.begin();
            int cost = top.first;
            int node = top.second;
            st.erase(top);
            visited[node] = true;

            for (auto x : adj[node])
            {
                if (!visited[x.first] && x.second < dist[x.first])
                {
                    auto iter = st.find({dist[x.first], x.first});
                    if (iter != st.end())
                        st.erase(iter);
                    dist[x.first] = x.second;
                    st.insert({dist[x.first], x.first});
                }
            }
        }

        return accumulate(begin(dist), end(dist), 0);
    }
};