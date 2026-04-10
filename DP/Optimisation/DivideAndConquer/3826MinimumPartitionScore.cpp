class Solution
{
public:
    using ll = long long int;

    vector<int> prefixSum;
    vector<vector<ll>> dp;

    ll cost(int i, int j)
    {
        ll s = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

        return s * (s + 1) / 2;
    }

    void solve(int l, int r, int optl, int optr, int k)
    {
        if (l > r)
            return;

        int mid = (l + r) >> 1;
        pair<ll, int> best = {LLONG_MAX, -1};

        for (int j = optl; j <= min(optr, mid); j++)
        {
            best =
                min(best, {(j > 0 ? dp[k - 1][j - 1] : 0) + cost(j, mid), j});
        }

        dp[k][mid] = best.first;

        int opt = best.second;
        solve(l, mid - 1, optl, opt, k);
        solve(mid + 1, r, opt, optr, k);
    }

    long long minPartitionScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        prefixSum.assign(n, 0);
        dp.assign(n, vector<ll>(n, 0));

        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = cost(0, j);
        }

        for (int i = 1; i < k; i++)
        {
            solve(0, n - 1, 0, n - 1,
                  i); // here i-> means, no of subarray to make
        }

        return dp[k - 1][n - 1];
    }
};