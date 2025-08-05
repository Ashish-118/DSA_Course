#define ll long long
const ll nax = 1e15;

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (online[u] && online[v] && w <= k)
            {
                adj[u].emplace_back(v, w);
            }
        }

        int low = 0, high = 1e9, ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            vector<ll> dis(n, nax);
            dis[0] = 0;
            set<pair<ll, int>> st;
            st.insert({0, 0});

            while (!st.empty())
            {
                auto p = *st.begin();
                st.erase(st.begin());

                for (auto nbs : adj[p.second])
                {
                    if (nbs.second >= mid && dis[nbs.first] > p.first + nbs.second)
                    {
                        st.erase({dis[nbs.first], nbs.first});
                        dis[nbs.first] = p.first + nbs.second;
                        st.insert({dis[nbs.first], nbs.first});
                    }
                }
            }

            if (dis[n - 1] <= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
