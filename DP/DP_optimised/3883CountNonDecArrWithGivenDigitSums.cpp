class Solution
{
public:
    int countArrays(vector<int> &digitSum)
    {
        int n = digitSum.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i <= 5000; i++)
        {
            int dsum = 0, z = i;
            while (z)
            {
                dsum += (z % 10);
                z /= 10;
            }
            mp[dsum].push_back(i);
        }

        const int mod = 1e9 + 7;

        vector<unordered_map<int, int>> dp(n);

        for (int x : mp[digitSum[0]])
        {
            dp[0][x] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            auto v1 = mp[digitSum[i - 1]];
            int m = v1.size();

            if (m > 0)
            {
                vector<int> pre(m);
                pre[0] = dp[i - 1][v1[0]];

                for (int j = 1; j < m; j++)
                {
                    pre[j] = (pre[j - 1] + dp[i - 1][v1[j]]) % mod;
                }

                auto v2 = mp[digitSum[i]];

                for (int x : v2)
                {
                    int idx =
                        upper_bound(v1.begin(), v1.end(), x) - v1.begin() - 1;
                    if (idx >= 0)
                    {
                        dp[i][x] = (dp[i][x] + pre[idx]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int x : mp[digitSum.back()])
        {
            ans = (ans + dp[n - 1][x]) % mod;
        }

        return ans;
    }
};