// User function Template for C++

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int findParent_NoPathCompression(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return findParent_NoPathCompression(parent, parent[node]); // no path compression O(V)
    }

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        sort(begin(edges), end(edges), cmp);

        vector<int> parent(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        int ans = 0;
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int parent_u = findParent_NoPathCompression(parent, u);
            int parent_v = findParent_NoPathCompression(parent, v);

            if (parent_u != parent_v)
            {
                parent[parent_v] = parent_u;
                ans += x[2];
            }
        }
        return ans;
    }
}; // here we are not using path compression to optimize the find operation in union-find structure

//----------------------------
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int findParent_pathCompression(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent_pathCompression(parent, parent[node]); // with path compression O(⍺(V))
    }

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        sort(begin(edges), end(edges), cmp);

        vector<int> parent(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        int ans = 0;
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int parent_u = findParent_pathCompression(parent, u);
            int parent_v = findParent_pathCompression(parent, v);

            if (parent_u != parent_v)
            {
                parent[parent_v] = parent_u;
                ans += x[2];
            }
        }
        return ans;
    }
}; // here we are using path compression to optimize the find operation in union-find structure

//---------------------------------------

// here we are using rank concept to find the union of two sets without path compression

// User function Template for C++
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int findParent_noPathCompression(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return findParent_noPathCompression(parent, parent[node]); // no path compression O(V)
    }

    void unionByRank(vector<int> &parent, vector<int> &rank, int parent_u, int parent_v) // O(1)
    {

        if (rank[parent_u] < rank[parent_v])
        {

            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {

            parent[parent_v] = parent_u;
        }
        else
        {
            rank[parent_u]++;
            parent[parent_v] = parent_u;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        sort(begin(edges), end(edges), cmp);

        vector<int> parent(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(V, 0);
        int ans = 0;
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int parent_u = findParent_noPathCompression(parent, u);
            int parent_v = findParent_noPathCompression(parent, v);

            if (parent_u != parent_v)
            { // to ensure both does not belong to the same component/set
                unionByRank(parent, rank, parent_u, parent_v);
                ans += x[2];
            }
        }
        return ans;
    }
};
//------------------------------------------
// here we are using rank concept to find the union of two sets with path compression

// User function Template for C++
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int findParent_pathCompression(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent_pathCompression(parent, parent[node]); // with path compression O(⍺(V))
    }

    void unionByRank(vector<int> &parent, vector<int> &rank, int parent_u, int parent_v) // O(1)
    {

        if (rank[parent_u] < rank[parent_v])
        {

            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {

            parent[parent_v] = parent_u;
        }
        else
        {
            rank[parent_u]++;
            parent[parent_v] = parent_u;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        sort(begin(edges), end(edges), cmp);

        vector<int> parent(V, 0);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(V, 0);
        int ans = 0;
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int parent_u = findParent_pathCompression(parent, u);
            int parent_v = findParent_pathCompression(parent, v);

            if (parent_u != parent_v)
            { // to ensure both does not belong to the same component/set
                unionByRank(parent, rank, parent_u, parent_v);
                ans += x[2];
            }
        }
        return ans;
    }
};
