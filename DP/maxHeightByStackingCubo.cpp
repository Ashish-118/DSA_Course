class Solution
{
public:
    bool check(vector<int> base, vector<int> newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        {
            return true;
        }
        else
            return false;
    }
    int solve(vector<vector<int>> &cuboids, int n, vector<int> &dp)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int maxi = cuboids[i][2];
            for (int j = i + 1; j < n; j++)
            {
                if (check(cuboids[j], cuboids[i]))
                {

                    maxi = max(maxi, dp[j] + cuboids[i][2]);
                }
            }
            dp[i] = maxi;
        }
        int ans = 0;
        for (auto x : dp)
        {

            ans = max(ans, x);
        }
        return ans;
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &x : cuboids)
        {
            sort(x.begin(), x.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        return solve(cuboids, n, dp);
    }
};