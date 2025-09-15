class Solution
{
public:
    pair<int, int> solve(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, vector<bool> &dfsVisited, char tar, string s)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        int nodeMatch = (s[node] == tar ? 1 : 0);

        int maxi = 0;
        bool hasCycle = true;
        bool hasNgb = false;
        for (auto &x : adj[node])
        {
            hasNgb = true;
            if (!visited[x])
            {
                auto res = solve(x, visited, adj, dfsVisited, tar, s);
                if (res.second)
                    continue;

                hasCycle = res.second;
                maxi = max(res.first, maxi);
            }
            else if (dfsVisited[x])
            {
                return {-1, true};
            }
        }

        if (hasNgb && hasCycle)
            return {-1, true};
        return {maxi + nodeMatch, false};
    }

    char maxFreq(string s)
    {

        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++; // count frequency
        }

        char mostOccuring = 'a';
        int maxCount = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > maxCount)
            {
                maxCount = freq[i];
                mostOccuring = 'a' + i;
            }
        }

        return mostOccuring;
    }
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.length();
        vector<bool> visited(n, false);
        vector<bool> dfsVisited(n, false);

        unordered_map<int, list<int>> adj;
        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
        }

        char mostFrequent = maxFreq(colors);

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                auto a = solve(i, visited, adj, dfsVisited, mostFrequent, colors);
                ans = max(a.first, ans);
            }
        }

        return ans;
    }
};