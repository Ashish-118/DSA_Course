class Solution
{
public:
    void dfs(int node, int parent, vector<int> &xorSubtree, vector<int> &inTime, vector<int> &outTime, int &timer, vector<int> &nums, unordered_map<int, list<int>> &adj)
    {
        xorSubtree[node] = nums[node];
        inTime[node] = timer;
        timer++;

        for (auto &ngb : adj[node])
        {
            if (ngb != parent)
            {
                dfs(ngb, node, xorSubtree, inTime, outTime, timer, nums, adj);
                xorSubtree[node] ^= xorSubtree[ngb];
            }
        }
        outTime[node] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int> &inTime, vector<int> &outTime)
    {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c)
    {
        int mini = min({a, b, c});
        int maxi = max({a, b, c});
        return maxi - mini;
    }
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();

        unordered_map<int, list<int>> adj;
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> xorSubtree(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;
        dfs(0, -1, xorSubtree, inTime, outTime, timer, nums, adj);

        int result = INT_MAX;

        for (int u = 1; u < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                int xor1;
                int xor2;
                int xor3;

                if (isAncestor(u, v, inTime, outTime))
                {

                    xor1 = xorSubtree[v];
                    xor2 = xorSubtree[u] ^ xor1;
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }
                else if (isAncestor(v, u, inTime, outTime))
                {
                    xor1 = xorSubtree[u];
                    xor2 = xorSubtree[v] ^ xor1;
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }
                else
                {
                    xor1 = xorSubtree[u];
                    xor2 = xorSubtree[v];
                    xor3 = xorSubtree[0] ^ xor1 ^ xor2;
                }
                result = min(result, getScore(xor1, xor2, xor3));
            }
        }

        return result;
    }
};