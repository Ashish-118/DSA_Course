class Solution
{
public:
    int countCommas(int n)
    {
        int count = 0;

        for (int i = 1000; i <= n; i++)
        {
            string num = to_string(i);

            count += (num.length() - 1) / 3;
        }

        return count;
    }
};