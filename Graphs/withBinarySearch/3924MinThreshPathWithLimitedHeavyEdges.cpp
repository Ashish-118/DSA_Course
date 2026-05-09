class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    bool poss(int source, int target, int th, int n, int k)
    {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;

        // (distance, node)
        set<pair<int, int>> st;
        st.insert({0, source});

        while (!st.empty())
        {
            auto front = *st.begin();
            st.erase(st.begin());

            int val = front.first;
            int node = front.second;

            for (auto ngb : adj[node])
            {
                int wt = (ngb.second > th ? 1 : 0);

                if (dist[ngb.first] > dist[node] + wt)
                {
                    if (dist[ngb.first] != INT_MAX)
                    {
                        st.erase({dist[ngb.first], ngb.first});
                    }

                    dist[ngb.first] = dist[node] + wt;
                    st.insert({dist[ngb.first], ngb.first});
                }
            }
        }

        return (dist[target] != INT_MAX && dist[target] <= k);
    }

    int minimumThreshold(int n, vector<vector<int>> &edges,
                         int source, int target, int k)
    {
        if (source == target)
            return 0;

        adj.clear();

        int maxi = -1;

        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
            maxi = max(maxi, e[2]);
        }

        int low = 0; // important: threshold can be 0
        int high = maxi;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (poss(source, target, mid, n, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};