class Solution
{
public:
    vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s,
                                vector<string> &queries)
    {
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        const int nax = log2(n);
        vector<vector<int>> parent(
            nax + 1,
            vector<int>(n, -1)); // parent[i][node] = 2^i (th) parent of node
        vector<int> depth(n, 0), mask(n, 0);
        function<void(int, int)> dfs = [&](int node, int par)
        {
            parent[0][node] = par; // 2^0th = 1st parent
            for (int nbs : adj[node])
            {
                if (nbs != par)
                {
                    depth[nbs] = depth[node] + 1;
                    mask[nbs] = mask[node] ^ (1 << (s[nbs] - 'a'));
                    dfs(nbs, node);
                }
            }
        };
        mask[0] = (1 << (s[0] - 'a'));
        dfs(0, -1);
        for (int k = 1; k <= nax; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (parent[k - 1][i] != -1)
                    parent[k][i] =
                        parent[k - 1][parent[k - 1][i]]; // 2^kth parent
            }
        }
        auto lca = [&](int l, int r)
        {
            if (depth[l] < depth[r])
                swap(l, r);
            int d = depth[l] - depth[r];
            while (d > 0)
            {
                int k = log2(d);
                l = parent[k][l];
                d -= (1 << k);
            }
            if (l == r)
                return l;
            for (int i = nax; i >= 0; i--)
            {
                if (parent[i][l] != -1 && parent[i][l] != parent[i][r])
                {
                    l = parent[i][l];
                    r = parent[i][r];
                }
            }
            return parent[0][l];
        };
        vector<bool> answer;
        for (auto &q : queries)
        {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update")
            {
                int u;
                char c;
                ss >> u >> c;
                int oldBit = (1 << (s[u] - 'a')), newBit = (1 << (c - 'a')),
                    diff = oldBit ^ newBit;
                if (diff != 0)
                {
                    s[u] = c;
                    function<void(int, int)> updateDfs = [&](int node,
                                                             int par)
                    {
                        mask[node] ^= diff;
                        for (int nbs : adj[node])
                        {
                            if (nbs != par && depth[nbs] > depth[node])
                                updateDfs(nbs, node);
                        }
                    };
                    updateDfs(u, parent[0][u]);
                }
            }
            else
            {
                int u, v;
                ss >> u >> v;
                int w = lca(u, v);
                int pathMask = mask[u] ^ mask[v] ^ (1 << (s[w] - 'a'));
                answer.push_back((pathMask & (pathMask - 1)) ==
                                 0); // 0,1 , builtinpopcount <=1
            }
        }
        return answer;
    }
};
