class Solution
{
public:
    string ans;
    int K;
    void solve(string temp, int n, char prev)
    {
        if (K == 0)
            return;
        else if (temp.length() == n)
        {

            if (K == 1)
            {
                ans = temp;
            }

            K--;
            return;
        }

        for (auto x : {'a', 'b', 'c'})
        {
            if (prev != x)
            {
                solve(temp + x, n, x);
            }
        }
    }
    string getHappyString(int n, int k)
    {
        K = k;
        solve("", n, '0');

        return ans;
    }
};