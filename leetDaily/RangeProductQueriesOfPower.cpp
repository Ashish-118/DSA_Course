class Solution
{
public:
    int mul(int a, int b)
    {
        return (int)((1LL * (a % mod) * (b % mod)) % mod);
    }

    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> power;

        for (int i = 0; i < 31; i++)
        {
            if ((n >> i) & 1)
            {
                power.push_back(pow(2, i));
            }
        }

        vector<int> result;
        for (auto &q : queries)
        {
            int ans = 1;
            for (int i = q[0]; i <= q[1]; i++)
            {
                ans = mul(ans, power[i]);
            }
            result.push_back(ans);
        }

        return result;
    }

private:
    static constexpr int mod = 1000000007;
};