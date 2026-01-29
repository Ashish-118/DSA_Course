class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        unordered_map<char, list<pair<char, int>>> adj;
        int v = original.size();
        vector<int> dist(26, INT_MAX);
        vector<vector<int>> costToChange(26, vector<int>(26, 0));

        for (int i = 0; i < v; i++)
        {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        auto dijkstra = [&](char s)
        {
            set<pair<int, char>> st;
            dist[s - 'a'] = 0;
            st.insert({0, s});

            while (!st.empty())
            {
                auto front = *st.begin();
                st.erase(front);
                int wt = front.first;
                char node = front.second;

                for (auto &ngb : adj[node])
                {
                    int edgeWeight = ngb.second;
                    char ngb_node = ngb.first;
                    int x = ngb_node - 'a';

                    if (dist[x] > wt + edgeWeight)
                    {
                        auto find = st.find({dist[x], ngb_node});
                        if (find != st.end())
                        {
                            st.erase(find);
                        }
                        dist[x] = wt + edgeWeight;
                        st.insert({dist[x], ngb_node});
                    }
                }
            }
        };

        for (int i = 0; i < 26; i++)
        {
            fill(begin(dist), end(dist), INT_MAX);
            dijkstra('a' + i);

            for (int j = 0; j < 26; j++)
            {

                costToChange[i][j] = dist[j];
            }
        }
        int n = source.length();

        long long TotalCost = 0;
        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {

                int val = costToChange[source[i] - 'a'][target[i] - 'a'];
                if (val == INT_MAX)
                    return -1;
                TotalCost += val;
            }
        }

        return TotalCost;
    }
};

// most optimal using floyd warshall

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {

        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
            {
                long long c = dist[source[i] - 'a'][target[i] - 'a'];
                if (c == LLONG_MAX)
                    return -1;
                ans += c;
            }
        }

        return ans;
    }
};
