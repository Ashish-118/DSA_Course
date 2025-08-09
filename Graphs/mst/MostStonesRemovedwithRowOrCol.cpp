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

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> rank(n, 0);

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto &x : adjacencyList[i])
            {
                int u = findParent(i, parent);
                int v = findParent(x, parent);

                if (u != v)
                {
                    dsu(u, v, parent, rank);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != i)
            {
                count++;
            }
        }
        return count;
    }
};