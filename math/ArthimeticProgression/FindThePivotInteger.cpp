class Solution
{
public:
    int pivotInteger(int n)
    {

        int sum = (n * (n + 1)) / 2;

        for (int i = 1; i <= n; i++)
        {
            int _x_sum = (i * (i + 1)) / 2;
            int x_n_sum = sum - _x_sum + i;

            if (_x_sum == x_n_sum)
                return i;
        }

        return -1;
    }
};