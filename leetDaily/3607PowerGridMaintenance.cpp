class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void dsu(vector<int> &rank, vector<int> &parent, int parentU, int parentV)
    {
        if (rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>> &connections,
                               vector<vector<int>> &queries)
    {
        vector<int> parent(c + 1, 0);
        unordered_map<int, bool> online;
        for (int i = 1; i <= c; i++)
        {
            parent[i] = i;
            online[i] = true;
        }

        vector<int> rank(c + 1, 0);

        for (auto x : connections)
        {
            int u = x[0];
            int v = x[1];

            int parentU = findParent(u, parent);
            int parentV = findParent(v, parent);
            if (parentU != parentV)
            {
                dsu(rank, parent, parentU, parentV);
            }
        }

        unordered_map<int, set<int>> grid;

        for (int i = 1; i <= c; i++)
        {
            findParent(i, parent); // <-- compress all paths
        }

        for (int i = 1; i <= c; i++)
        {
            grid[parent[i]].insert(i);
        }

        vector<int> ans;

        for (auto query : queries)
        {
            int type = query[0];
            int node = query[1];

            if (type == 1)
            {
                if (online[node])
                    ans.push_back(node);
                else
                {
                    if (!grid[parent[node]].empty())
                    {

                        ans.push_back(*grid[parent[node]].begin());
                    }
                    else
                        ans.push_back(-1);
                }
            }
            else
            {
                online[node] = false;
                auto it = grid[parent[node]].find(node);

                if (it != grid[parent[node]].end())
                {
                    grid[parent[node]].erase(it);
                }
            }
        }

        return ans;
    }
};