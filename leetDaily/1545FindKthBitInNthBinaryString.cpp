class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string s = "0";

        for (int i = 2; i <= n; i++)
        {
            string rev = s;
            for (auto &x : rev)
            {
                if (x == '1')
                    x = '0';
                else
                    x = '1';
            }

            reverse(rev.begin(), rev.end());

            s += "1" + rev;
        }

        return s[k - 1];
    }
};