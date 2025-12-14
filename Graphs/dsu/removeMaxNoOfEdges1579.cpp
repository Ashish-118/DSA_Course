class dsu
{
public:
    vector<int> rank;
    vector<int> parent;

    dsu(int n)
    {
        rank = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int Findparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = Findparent(parent[node]);
    }

    void unionByRank(int parentU, int parentV)
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
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        int Alice_component = n;
        int bob_component = n;
        int usedEdge = 0;

        dsu alice(n);
        dsu bob(n);

        auto cmp = [&](vector<int> &a, vector<int> &b)
        {
            return a[0] > b[0];
        };
        sort(begin(edges), end(edges), cmp);

        for (auto &x : edges)
        {
            int type = x[0];
            bool used = false;
            if (type == 3 || type == 1)
            {
                int parentU = alice.Findparent(x[1]);
                int parentV = alice.Findparent(x[2]);

                if (parentU != parentV)
                {
                    alice.unionByRank(parentU, parentV);
                    Alice_component--;
                    used = true;
                }
            }

            if (type == 3 || type == 2)
            {
                int parentU = bob.Findparent(x[1]);
                int parentV = bob.Findparent(x[2]);

                if (parentU != parentV)
                {
                    bob.unionByRank(parentU, parentV);
                    bob_component--;
                    used = true;
                }
            }

            if (used)
                usedEdge++;
        }

        if (Alice_component == 1 && bob_component == 1)
        {
            return edges.size() - usedEdge;
        }
        else
        {
            return -1;
        }
    }
};