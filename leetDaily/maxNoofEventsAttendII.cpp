class Solution
{
public:
    int solve(vector<vector<int>> &ev, int k, int curr, int n, int prev, vector<vector<int>> &dp)
    {
        if (curr >= n)
        {
            return 0;
        }

        if (dp[curr][k] != -1)
            return dp[curr][k];

        int maxi = 0;
        for (int j = curr; j < n; j++)
        {
            int inc = 0;

            if ((k == 1) && (curr == 0 || (ev[prev][1] < ev[j][0])))
            {
                inc = ev[j][2];
            }
            else if (curr == 0 || (ev[prev][1] < ev[j][0]))
            {
                inc = solve(ev, k - 1, j + 1, n, j, dp) + ev[j][2];
            }

            maxi = max(maxi, inc);
        }

        dp[curr][k] = maxi;
        return maxi;
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), cmp);
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return solve(events, k, 0, events.size(), -1, dp);
    }
}; // time complexity O(n^2 * k), where n is the number of events and k is the maximum number of events that can be attended.