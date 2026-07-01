class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<long long> p0(n, 0);
        vector<long long> p1(n, 0);
        vector<long long> p2(n, 0);
        p0[0] = nums[0];
        p1[0] = 1LL * nums[0] * k;
        p2[0] = nums[0];

        // operation -> multiplication
        long long ansMul = max({p0[0], p1[0], p2[0]});

        for (int i = 1; i < n; i++)
        {
            p0[i] = max(1LL * nums[i], p0[i - 1] + nums[i]);
            ansMul = max(ansMul, p0[i]);
        }

        for (int i = 1; i < n; i++)
        {
            p1[i] = max({1LL * nums[i] * k, p0[i - 1] + 1LL * nums[i] * k,
                         p1[i - 1] + 1LL * nums[i] * k});
            ansMul = max(ansMul, p1[i]);
        }

        for (int i = 1; i < n; i++)
        {
            p2[i] =
                max({1LL * nums[i], p1[i - 1] + nums[i], p2[i - 1] + nums[i]});
            ansMul = max(ansMul, p2[i]);
        }

        // operation -> division
        p1.assign(n, 0);
        p2.assign(n, 0);

        p1[0] = nums[0] / k;
        p2[0] = nums[0];

        long long ansDiv = max({p0[0], p1[0], p2[0]});

        for (int i = 1; i < n; i++)
        {
            p1[i] = max({1LL * (nums[i] / k), p0[i - 1] + 1LL * (nums[i] / k),
                         p1[i - 1] + 1LL * (nums[i] / k)});
            ansDiv = max(ansDiv, p1[i]);
        }

        for (int i = 1; i < n; i++)
        {
            p2[i] =
                max({1LL * nums[i], p1[i - 1] + nums[i], p2[i - 1] + nums[i]});
            ansDiv = max(ansDiv, p2[i]);
        }

        return max(ansDiv, ansMul);
    }
};