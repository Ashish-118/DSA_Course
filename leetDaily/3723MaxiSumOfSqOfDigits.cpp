class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        int sum1 = 0;
        string ans = "";

        for (int i = 0; i < num; i++)
        {
            for (int d = 9; d >= 0; d--)
            {
                if (sum1 + d <= sum)
                {
                    ans += ('0' + d);
                    sum1 += d;
                    break;
                }
            }
        }

        if (sum1 != sum)
        {
            return "";
        }

        return ans;
    }
};