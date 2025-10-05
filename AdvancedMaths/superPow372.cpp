
class Solution
{

public:
    int exp(int a, int b, int M)
    {
        long long ans = 1;
        while (b)
        {
            if (b & 1)
            {
                ans = (ans * a) % M;
            }

            a = (a * 1LL * a) % M;
            b >>= 1;
        }

        return ans % M;
    }
    int superPow(int a, vector<int> &b)
    {

        int b_ = 0;
        int n = b.size();
        int M1 = 1140;

        for (int i = 0; i < n; i++)
        {

            b_ = (b_) + (b[i] * exp(10, n - 1 - i, M1));
        }

        return exp(a, b_, 1337);
    }
};