class Solution
{
public:
    using vec = vector<int>;
    vector<vec> v;
    int t[1001][1501][2];

    int solve(int i, int repeat, int budget, int n)
    {
        if (i >= n)
        {
            return 0;
        }
        else if (v[i][0] > budget)
        {
            return t[i][budget][repeat] = solve(i + 1, 0, budget, n);
        }

        if (t[i][budget][repeat] != -1)
        {
            return t[i][budget][repeat];
        }

        int take = 0;
        if (repeat)
        {
            take = 1;
        }
        else
        {
            take = v[i][1];
        }

        int rep = solve(i, 1, budget - v[i][0], n);
        int nxt = solve(i + 1, 0, budget - v[i][0], n);

        int notTake = solve(i + 1, 0, budget, n);

        return t[i][budget][repeat] = max(take + max(rep, nxt), notTake);
    }

    int maximumSaleItems(vector<vector<int>> &items, int budget)
    {
        int n = items.size();

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                if (items[j][0] % items[i][0] == 0)
                {
                    count++;
                }
            }

            v.push_back({items[i][1], count});
        }
        memset(t, -1, sizeof(t));

        return solve(0, 0, budget, n);
    }
};