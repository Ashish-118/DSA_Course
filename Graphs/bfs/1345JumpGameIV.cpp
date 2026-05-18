class Solution
{
public:
    unordered_map<int, unordered_set<int>> adj;
    vector<bool> visited;

    int minJumps(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            adj[x].insert(i);
        }

        visited.assign(n, false);

        queue<pair<int, int>> q;

        q.push({0, 0});

        while (!q.empty())
        {
            auto front = q.front();
            int node = front.first;
            int cost = front.second;
            q.pop();

            if (node == n - 1)
            {
                return cost;
            }

            for (auto ngb : adj[arr[node]])
            {
                if (!visited[ngb])
                {
                    q.push({ngb, cost + 1});
                    visited[ngb] = true;
                }
            }
            adj[arr[node]].clear();

            if (node - 1 >= 0 && !visited[node - 1])
            {
                q.push({node - 1, cost + 1});
                visited[node - 1] = true;
            }

            if (node + 1 < n && !visited[node + 1])
            {
                q.push({node + 1, cost + 1});
                visited[node + 1] = true;
            }
        }

        return -1;
    }
};