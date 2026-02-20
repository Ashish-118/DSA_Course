

class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<int> parent;
    vector<int> rank;

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int parentU, int parentV)
    {
        if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else if (rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }
        else
        {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        set<pair<int, pair<int, int>>> st;
        parent = vector<int>(n * n, 0);
        rank = vector<int>(n * n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int node = n * i + j;
                parent[node] = node;

                cout << "node " << node << endl;

                for (auto [dx, dy] : dir)
                {
                    int x_ = i + dx;
                    int y_ = j + dy;

                    if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < n)
                    {

                        int ngb = n * x_ + y_;
                        int weight = max(grid[i][j], grid[x_][y_]);

                        int u = min(node, ngb);
                        int v = max(node, ngb);

                        cout << " ngb " << ngb << " weight " << weight << endl;

                        st.insert({weight, {u, v}});
                    }
                }
            }
        }

        int destNode = n * n - 1;

        int maxTime = 0;
        for (auto s : st)
        {

            auto top = s;

            int u = top.second.first;
            int v = top.second.second;
            int cost = top.first;

            int parentU = findParent(u);
            int parentV = findParent(v);

            if (parentU != parentV)
            {
                unionByRank(parentU, parentV);
                maxTime = max(maxTime, cost);
            }

            if (findParent(0) == findParent(destNode))
                break;
        }

        return maxTime;
    }
};