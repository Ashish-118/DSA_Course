// User function Template for C++
class Solution
{
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // path compression
    }

    void unionByRank(vector<int> &parent, vector<int> &rank, int u, int v)
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<vector<int>> nodes(n, vector<int>(m));
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                node++;
                nodes[i][j] = node;
            }
        }

        vector<int> parent(n * m, -1);
        vector<int> rank(n * m, 0);

        auto checkSafe = [&](int x, int y)
        {
            return x >= 0 && y >= 0 && x < n && y < m && (parent[nodes[x][y]] != -1);
        };

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> ans;
        // int count = 0;

        for (auto &query : operators)
        {
            int x = query[0];
            int y = query[1];
            int u = nodes[x][y];

            if (parent[u] == -1)
            { // If it's water, make it land
                parent[u] = u;
                // count++;

                for (auto d : dir)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (checkSafe(nx, ny))
                    {
                        int v = nodes[nx][ny];
                        int pu = findParent(parent, u);
                        int pv = findParent(parent, v);
                        if (pu != pv)
                        {
                            unionByRank(parent, rank, pu, pv);
                            // count--;
                        }
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < n * m; i++)
            {
                if (parent[i] == i)
                    count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};

// optimal way to calculate count-------------------------------------------

// User function Template for C++
class Solution
{
    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]); // path compression
    }

    void unionByRank(vector<int> &parent, vector<int> &rank, int u, int v)
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<vector<int>> nodes(n, vector<int>(m));
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                node++;
                nodes[i][j] = node;
            }
        }

        vector<int> parent(n * m, -1);
        vector<int> rank(n * m, 0);

        auto checkSafe = [&](int x, int y)
        {
            return x >= 0 && y >= 0 && x < n && y < m && (parent[nodes[x][y]] != -1);
        };

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> ans;
        int count = 0;

        for (auto &query : operators)
        {
            int x = query[0];
            int y = query[1];
            int u = nodes[x][y];

            if (parent[u] == -1)
            { // If it's water, make it land
                parent[u] = u;
                count++;

                for (auto d : dir)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (checkSafe(nx, ny))
                    {
                        int v = nodes[nx][ny];
                        int pu = findParent(parent, u);
                        int pv = findParent(parent, v);
                        if (pu != pv)
                        {
                            unionByRank(parent, rank, pu, pv);
                            count--;
                        }
                    }
                }
            }
            ans.push_back(count);
        }

        return ans;
    }
};
