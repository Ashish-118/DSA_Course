class Solution
{
public:
    unordered_map<int, list<int>> adj;
    vector<bool> visited;

    void solve(int idx, vector<int> &indices)
    {
        indices.push_back(idx);
        visited[idx] = true;

        for (auto ngb : adj[idx])
        {
            if (!visited[ngb])
            {
                solve(ngb, indices);
            }
        }
    }
    int minimumHammingDistance(vector<int> &source, vector<int> &target,
                               vector<vector<int>> &allowedSwaps)
    {

        for (auto x : allowedSwaps)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int n = source.size();

        visited.assign(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                vector<int> indices;
                solve(i, indices);

                unordered_map<int, int> elements;
                for (auto j : indices)
                {
                    elements[source[j]]++;
                }

                for (auto j : indices)
                {
                    if (elements.count(target[j]))
                    {
                        elements[target[j]]--;
                        if (elements[target[j]] == 0)
                        {
                            elements.erase(target[j]);
                        }
                    }
                }

                for (auto &x : elements)
                {
                    ans += x.second;
                }
            }
        }

        return ans;
    }
};