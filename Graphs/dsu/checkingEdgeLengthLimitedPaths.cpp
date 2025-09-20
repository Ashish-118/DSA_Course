class Solution
{
public:
    int Find_parent(int node, vector<int> &parent)
    {
        if (node == parent[node])
            return node;

        return parent[node] = Find_parent(parent[node], parent);
    }

    void unionByRank(int parentU, int parentV, vector<int> &rank, vector<int> &parent)
    {
        if (rank[parentU] > rank[parentV])
        {
            rank[parentU]++;
            parent[parentV] = parentU;
        }
        else if (rank[parentU] < rank[parentV])
        {
            rank[parentV]++;
            parent[parentU] = parentV;
        }
        else
        {
            rank[parentV]++;
            parent[parentU] = parentV;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        auto edgesSort = [&](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        };

        auto querySort = [&](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        };

        sort(begin(edgeList), end(edgeList), edgesSort);

        for (int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        sort(begin(queries), end(queries), querySort);

        int j = 0;
        vector<bool> ans(queries.size(), false);

        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<int> rank(n, 0);

        for (auto &query : queries)
        {
            int limit = query[2];

            while (j < edgeList.size() && limit > edgeList[j][2])
            {

                int u = Find_parent(edgeList[j][0], parent);
                int v = Find_parent(edgeList[j][1], parent);
                if (u != v)
                {
                    unionByRank(u, v, rank, parent);
                }
                j++;
            }

            int index = query[3];
            int u = Find_parent(query[0], parent);
            int v = Find_parent(query[1], parent);

            if (u == v)
                ans[index] = true;
        }
        return ans;
    }
};