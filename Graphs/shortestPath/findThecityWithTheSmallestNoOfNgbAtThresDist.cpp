class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0; // for diagonal elements -->0

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (dist[i][k] == INT_MAX or dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int mini = INT_MAX;
        int ansNode = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (auto &y : dist[i])
            {
                if (y <= distanceThreshold)
                    count++;
            }
            cout << count << endl;
            if (mini > count)
            {
                ansNode = i;
                mini = count;
            }
            else if (mini == count)
            {
                ansNode = i;
            }
        }

        return ansNode;
    }
};