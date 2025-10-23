class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<int> result(n, 0);
        vector<vector<int>> shortestPath(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            shortestPath[i][i] = 0;
            if (i - 1 >= 0)
            {
                shortestPath[i][i - 1] = 1;
                shortestPath[i - 1][i] = 1;
            }
            if (i + 1 < n)
            {
                shortestPath[i][i + 1] = 1;
                shortestPath[i + 1][i] = 1;
            }
        }

        if (x != y)
        {
            shortestPath[x - 1][y - 1] = 1;
            shortestPath[y - 1][x - 1] = 1;
        }

        for (int node = 0; node < n; node++)
        {
            for (int source = 0; source < n; source++)
            {
                for (int destination = 0; destination < n; destination++)
                {
                    if (shortestPath[source][node] == INT_MAX ||
                        shortestPath[node][destination] == INT_MAX)
                        continue;

                    shortestPath[source][destination] =
                        min(shortestPath[source][destination],
                            shortestPath[source][node] +
                                shortestPath[node][destination]);
                }
            }
        }

        for (int source = 0; source < n; source++)
        {
            for (int destination = 0; destination < n; destination++)
            {
                int minPath = shortestPath[source][destination];
                if (minPath == 0 || minPath == INT_MAX)
                    continue; // skip invalid
                result[minPath - 1]++;
            }
        }

        return result;
    }
}; // time complexity : O(n^3), space complexity : O(n^2)