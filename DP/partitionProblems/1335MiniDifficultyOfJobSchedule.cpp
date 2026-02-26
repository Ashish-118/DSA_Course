// recursive+memo

class Solution
{
public:
    int t[301][11];
    int solve(int d, int i, vector<int> &jobDifficulty)
    {
        if (i >= jobDifficulty.size())
        {
            if (d)
                return INT_MAX;
            else
                return 0;
        }
        else if (d == 0)
            return INT_MAX;

        if (t[i][d] != -1)
            return t[i][d];

        int ans = INT_MAX;
        int maxi = -1;

        for (int k = i; k < jobDifficulty.size(); k++)
        {
            maxi = max(maxi, jobDifficulty[k]);
            int ret = solve(d - 1, k + 1, jobDifficulty);
            if (ret != INT_MAX)
                ans = min(ans, maxi + ret);
        }

        return t[i][d] = ans;
    }
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        memset(t, -1, sizeof(t));
        int ans = solve(d, 0, jobDifficulty);
        return ans == INT_MAX ? -1 : ans;
    }
};