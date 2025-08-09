class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node], parent);
    }

    void dsu(int parentU, int parentV, vector<int> &parent, vector<int> &rank)
    {

        if (rank[parentU] < rank[parentV])
        {
            rank[parentV]++;
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV])
        {
            rank[parentU]++;
            parent[parentV] = parentU;
        }
        else
        {
            rank[parentU]++;
            parent[parentV] = parentU;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int free = 0;
        int disconnected = -1;
        for (auto x : connections)
        {
            int u = findParent(x[0], parent);
            int v = findParent(x[1], parent);

            if (u != v)
            {
                dsu(u, v, parent, rank);
            }
            else
            {
                free++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == parent[i])
                disconnected++;
        }

        if (disconnected <= free)
            return disconnected;
        else
            return -1;
    }
};