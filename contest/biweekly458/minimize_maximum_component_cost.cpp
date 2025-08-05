class Solution
{

    vector<int> parent;

private:
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i != j)
        {
            parent[i] = j;
            return true;
        }
        return false;
    }

    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }

public:
    int minCost(int n, vector<vector<int>> &edges, int k)
    {

        sort(edges.begin(), edges.end(), comp);

        parent.resize(n);

        int cnt = n;

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (unite(u, v))
            {
                cnt--;
            }
            if (cnt == k)
                return w;
        }
        return 0;
    }
};