class Solution
{
public:
    bool dfs(int node, vector<int> &leftChild, vector<int> &rightChild,
             vector<bool> &visited)
    {
        if (visited[node])
            return false; // cycle or duplicate parent
        visited[node] = true;

        if (leftChild[node] != -1 &&
            !dfs(leftChild[node], leftChild, rightChild, visited))
            return false;

        if (rightChild[node] != -1 &&
            !dfs(rightChild[node], leftChild, rightChild, visited))
            return false;

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                                 vector<int> &rightChild)
    {

        vector<int> indegree(n, 0);

        // Count indegrees
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
                indegree[leftChild[i]]++;
            if (rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }

        // Find root (indegree = 0)
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (root != -1)
                    return false; // more than one root
                root = i;
            }
        }

        if (root == -1)
            return false; // no root (every node has a parent)

        // DFS from root
        vector<bool> visited(n, false);
        if (!dfs(root, leftChild, rightChild, visited))
            return false;

        // Check if all nodes were reached
        for (bool v : visited)
            if (!v)
                return false;

        return true;
    }
};

/// using dsu

class Solution
{
public:
    vector<int> parent;
    int components;

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int par, int child)
    {
        int child_ka_parent = find(child);

        // child_ka_parent != child --> Child had already some other parent
        if (child_ka_parent != child)
            return false;

        int parent_ka_parent = find(par);
        // parent_ka_parent == child_ka_parent ---> Parallel edge (It means, already they were connected by another edge)
        if (parent_ka_parent == child_ka_parent)
        {
            return false;
        }

        parent[child] = par;
        components--;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        components = n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] >= 0 && !Union(i, leftChild[i]))
            {
                return false;
            }
            if (rightChild[i] >= 0 && !Union(i, rightChild[i]))
            {
                return false;
            }
        }

        return components == 1;
    }
};
