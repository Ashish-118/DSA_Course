// class Solution
// {
// public:
//     using p = pair<int, int>;
//     map<p, bool> ans;

//     bool dfs(int target, int node, unordered_map<int, list<p>> &adj,
//              vector<int> &visited, int cost, int n)
//     {
//         if (node == n - 1)
//             return true;
//         visited[node] = true;
//         int ret = false;

//         for (auto &ngb : adj[node])
//         {
//             int neighbour = ngb.first;
//             int w = ngb.second;

//             if (!visited[neighbour] && w + cost <= target)
//             {
//                 if (dfs(target, neighbour, adj, visited, cost + w, n))
//                 {
//                     ans[{node, neighbour}] = true;
//                     ret = true;
//                 }
//             }
//         }

//         visited[node] = false;

//         return ret;
//     }
//     vector<bool> findAnswer(int n, vector<vector<int>> &edges)
//     {
//         int cost = 0;
//         priority_queue<p, vector<p>, greater<p>> pq;
//         pq.push({0, 0});

//         unordered_map<int, list<p>> adj;
//         for (auto x : edges)
//         {
//             adj[x[0]].push_back({x[1], x[2]});
//             adj[x[1]].push_back({x[0], x[2]});
//         }

//         vector<int> visited(n, false);
//         vector<int> dist(n, INT_MAX);
//         dist[0] = 0;
//         // visited[0]=true;
//         while (!pq.empty())
//         {
//             p p1 = pq.top();
//             pq.pop();
//             int cost = p1.first;
//             int node = p1.second;
//             if (cost > dist[node])
//             {
//                 continue;
//             }
//             for (auto ngb : adj[node])
//             {
//                 if (dist[ngb.first] > cost + ngb.second)
//                 {
//                     dist[ngb.first] = cost + ngb.second;
//                     pq.push({dist[ngb.first], ngb.first});
//                 }
//             }
//         }
//         cost = dist[n - 1];
//         dfs(cost, 0, adj, visited, 0, n);
//         vector<bool> res(edges.size(), false);
//         for (int i = 0; i < edges.size(); i++)
//         {
//             res[i] =
//                 ans[{edges[i][0], edges[i][1]}] | ans[{edges[i][1], edges[i][0]}];
//         }

//         return res;
//     }
// }; // we can use dp to optimize it to an great extend

// approach 2. --using dijkstra's algorithm to find the shortest path from both sides

// Using Dijkstra's
// T.C : O(elogv) , where n = number of vertices, E = number of edges
// S.C : O(n+E)
class Solution
{
public:
    typedef long long ll;
    typedef pair<ll, ll> P;

    vector<int> dijkstra(unordered_map<int, vector<P>> &adj, int src, int n)
    {
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty())
        {

            ll currWt = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (visited[currNode] == true)
            {
                continue;
            }

            for (auto adj : adj[currNode])
            {
                int nextNode = adj.first;
                ll nextWt = adj.second;

                if (dist[nextNode] > currWt + nextWt)
                {
                    dist[nextNode] = currWt + nextWt;
                    pq.push({currWt + nextWt, nextNode});
                }
            }

            visited[currNode] = true;
        }

        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        int E = edges.size();

        unordered_map<int, vector<P>> adj;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> fromSrc = dijkstra(adj, 0, n);
        vector<int> fromDest = dijkstra(adj, n - 1, n);

        vector<bool> result(E, false);

        for (int i = 0; i < E; i++)
        {

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            ll distFromSrc = fromSrc[u];   // x
            ll distFromDest = fromDest[v]; // y

            if (distFromSrc + w + distFromDest == fromSrc[n - 1])
            {
                result[i] = true;
            }

            distFromSrc = fromSrc[v];   // x
            distFromDest = fromDest[u]; // y
            if (distFromSrc + w + distFromDest == fromSrc[n - 1])
            {
                result[i] = true;
            }
        }

        return result;
    }
};
