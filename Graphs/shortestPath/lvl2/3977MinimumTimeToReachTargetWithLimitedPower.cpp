class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n,
                                       vector<long long>(power + 1, LLONG_MAX));

        set<vector<long long>> st;

        // {time, powerUsed, node}
        st.insert({0, 0, source});
        dist[source][0] = 0;

        while (!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            long long minTime = top[0];
            int minPow = top[1];
            int node = top[2];

            if (minTime != dist[node][minPow])
                continue;

            if (node == target) {
                return {minTime, power - minPow};
            }

            for (auto [v, wt] : adj[node]) {

                int newPow = minPow + cost[node];
                if (newPow > power)
                    continue;

                long long newTime = minTime + wt;

                if (dist[v][newPow] > newTime) {
                    dist[v][newPow] = newTime;
                    st.insert({newTime, newPow, v});
                }
            }
        }

        return {-1, -1};
    }
};