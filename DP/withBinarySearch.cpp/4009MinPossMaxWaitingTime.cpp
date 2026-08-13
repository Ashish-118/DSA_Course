class Solution
{
public:
    int minMaxWaitingTime(vector<int> &demand, vector<int> &fuel)
    {

        int n = demand.size();

        int mx = -1;

        auto check = [&](int mx, int bound)
        {
            int dp[51][51][21][21];
            memset(dp, 0, sizeof(dp));

            dp[0][0][0][0] = 1;

            int cur = 0;

            for (int i = 0; i < mx; i += 1)
            {

                for (int j = 0; j <= fuel[0]; j += 1)
                {

                    // j = amt of fuel from 1st despenser, k = amt from 2nd despenser
                    int k = cur - j;

                    if (k < 0 || k > fuel[1])
                        continue;

                    for (int x = 0; x <= 20; x += 1)
                    {
                        for (int y = 0; y <= 20; y += 1)
                        {

                            if (dp[i][j][x][y] == 0)
                                continue;

                            // assign the car to 1st despenser
                            if (j + demand[i] <= fuel[0] && x <= bound)
                            {
                                dp[i + 1][j + demand[i]][demand[i]][max(0, y - x)] = 1;
                            }

                            // assign the car to 2nd despenser
                            if (k + demand[i] <= fuel[1] && y <= bound)
                            {
                                dp[i + 1][j][max(0, x - y)][demand[i]] = 1;
                            }
                        }
                    }
                }

                cur += demand[i];
            }

            for (int i = 0; i <= fuel[0]; i += 1)
            {
                for (int x = 0; x <= 20; x += 1)
                {
                    for (int y = 0; y <= 20; y += 1)
                    {
                        if (dp[mx][i][x][y])
                        {
                            return 1;
                        }
                    }
                }
            }

            return 0;
        };

        for (int i = n; i >= 1; i -= 1)
        {
            if (check(i, 20))
            {
                mx = i;
                break;
            }
        }

        if (mx == -1)
        {
            return -1;
        }

        int l = 0, r = 20;
        int ans = 0;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (check(mx, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }
};