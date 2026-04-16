class TreeAncestor
{
public:
    vector<vector<int>> table;
    int LOG;

    TreeAncestor(int n, vector<int> &parent)
    {
        LOG = 16;
        table.assign(LOG, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            table[0][i] = parent[i];
        }

        for (int lvl = 1; lvl < LOG; lvl++)
        {
            for (int node = 0; node < n; node++)
            {
                if (table[lvl - 1][node] != -1)
                    table[lvl][node] = table[lvl - 1][table[lvl - 1][node]];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int ancestor = node;

        for (int i = 0; i < LOG; i++)
        {
            if (k & (1 << i))
            {
                if (ancestor == -1)
                    return -1;
                =
                    ancestor = table[i][ancestor];
            }
        }

        return ancestor;
    }
};
