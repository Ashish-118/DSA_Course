class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> graph;
    int N;
    Graph(int n, vector<vector<int>> &edges)
    {
        for (auto x : edges)
        {
            graph[x[0]].push_back({x[1], x[2]});
        }
        N = n;
    }

    void addEdge(vector<int> edge)
    {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> dist(N, INT_MAX);
        dist[node1] = 0;

        set<pair<int, int>> st;
        st.insert({0, node1});

        while (!st.empty())
        {
            auto top = *st.begin();
            int cost = top.first;
            int node = top.second;
            st.erase(st.begin());
            for (auto ngb : graph[node])
            {
                if (cost + ngb.second < dist[ngb.first])
                {
                    auto find = st.find({dist[ngb.first], ngb.first});
                    if (find != st.end())
                    { // ✅ always check before erase
                        st.erase(find);
                    }
                    dist[ngb.first] = cost + ngb.second;
                    st.insert({dist[ngb.first], ngb.first});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */