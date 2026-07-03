class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    bool poss(long long k, int cap, int n)
    {
        vector<long long> dist(n, LLONG_MAX);

        set<pair<long long, int>> st;
        st.insert({0, 0});
        dist[0] = 0;

        long long finalCost = -1;
        while (!st.empty())
        {
            auto top = *st.begin();
            st.erase(st.begin());
            int node = top.second;
            long long cost = top.first;

            if (dist[node] < cost)
                continue;

            if (node == n - 1)
            {
                finalCost = cost;
                break;
            }

            for (auto ngb : adj[node])
            {
                if (ngb.second < cap)
                    continue;

                if (dist[ngb.first] > (cost + ngb.second))
                {
                    dist[ngb.first] = (cost + ngb.second);
                    st.insert({cost + ngb.second, ngb.first});
                }
            }
        }

        return (finalCost == -1 || finalCost > k ? false : true);
    }
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                         long long k)
    {

        int n = online.size();

        for (auto e : edges)
        {
            if (!online[e[0]] || !online[e[1]])
            {
                continue;
            }

            adj[e[0]].push_back({e[1], e[2]});
        }

        int lo = 0, hi = 1e9;

        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (poss(k, mid, n))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};