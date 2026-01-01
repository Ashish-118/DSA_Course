class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionRank(int parentU, int parentV)
    {
        if (rank[parentV] > rank[parentU])
        {
            parent[parentU] = parentV;
        }
        else if (rank[parentV] < rank[parentU])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent = vector<int>(26);
        rank = vector<int>(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (auto eq : equations)
        {
            if (eq[1] == '=')
            {
                int parentU = findParent(eq[0] - 'a');
                int parentV = findParent(eq[3] - 'a');
                unionRank(parentU, parentV);
            }
        }

        for (auto eq : equations)
        {
            if (eq[1] == '!')
            {
                int parentU = findParent(eq[0] - 'a');
                int parentV = findParent(eq[3] - 'a');
                if (parentU == parentV)
                    return false;
            }
        }

        return true;
    }
};