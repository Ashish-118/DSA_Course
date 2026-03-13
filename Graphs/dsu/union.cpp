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

// *** Important Note ****

/*

Union - Find / Disjoint Set Complexity Explanation

                   There are three common optimizations used in Union -
    Find(DSU) :

    1. Union by Rank(or Size) 2. Path Compression
    3. Both combined

    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

    1. Union by Rank Only

    If we use only union by rank,
    the height of the tree is controlled.

    The idea is that we always attach the smaller tree under the larger tree(or lower rank under higher rank)
        .

    When two trees of the same rank are merged,
    the rank increases by 1.

    Important property : If a tree has rank r,
                         it must contain at least 2 ^ r nodes.

                                                      This means the maximum rank possible is log2(n)
                                                          .

                                                      Therefore the maximum height of the tree is at most log(n)
                                                          .

                                                      Because the find() operation follows the tree height,
                         the complexity becomes :

    find(x) = O(log n)

        So with union by rank only : Time complexity per operation = O(log n)

    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

    2. Path Compression Only

           Path compression works during the find() operation.
          When we perform find(x),

    we recursively go to the root of the tree.While returning,
    we make every node along the path directly point to the root.

                         Example idea :

    Before find : 1->2->3->4->5

    If we call find(5),
    path compression changes the structure so that :

                         2->1 3->1 4->1 5->1

                         Now all nodes directly point to the root.

                         Future find operations become very fast.

                         However,
    path compression alone does not prevent the tree from initially becoming very deep.The first find operation could still take O(n)
in the worst case.

    But after several operations,
    the trees become flatter.

    Because of this flattening effect,
    the average behavior across many operations becomes roughly O(log n).

    That is why we sometimes write:

~O(log n)

        The "~" symbol means "approximately" or
    "roughly behaves like".

    It is not a strict theoretical bound,
    but an observed average behavior.


    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
    3. Union by Rank + Path Compression

          When we combine both optimizations :

    -Union by rank keeps the tree from becoming too tall.-
        Path compression flattens the tree whenever find() is called.

        Robert Tarjan proved that this combination gives an amortized time complexity of :

    O(alpha(n))

        where alpha(n)
is the inverse Ackermann function.

    -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

    4. What is the Inverse Ackermann Function

        The Ackermann function grows extremely fast.

    Its inverse
    alpha(n) grows extremely slowly.

For all practical values of n:

n = 10^6      -> alpha(n) <= 4
n = 10^18     -> alpha(n) <= 4
Even for astronomically large numbers alpha(n) <= 5

So in practice:

O(alpha(n)) ≈ O(1)

This is why Union-Find with both optimizations is considered almost constant time.

---------------------------------------

Summary

Naive Union-Find                 -> O(n)
Union by Rank only               -> O(log n)
Path Compression only            -> ~O(log n)
Union by Rank + Path Compression -> O(alpha(n)) ≈ O(1)

*/
