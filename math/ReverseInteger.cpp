class Solution
{
public:
    int reverse(int x)
    {
        string str = to_string(x);
        int sign = 0;
        if (str[0] == '-')
        {
            sign = 1;
            str = str.substr(1);
        }
        if (x == INT_MAX || x == INT_MIN)
            return 0;

        int l = str.length();
        int num = abs(x);

        int num2 = 0;

        for (int i = 0; i < l; i++)
        {
            int d = str[i] - '0';
            int diff = INT_MAX - num2;

            if (i == 9 && d > 2)
                return 0;

            int val = (d * pow(10, i));

            if (sign == 0 && diff < val || sign == 1 && diff < val - 1)
                return 0;

            num2 += val;
        }

        return sign == 0 ? num2 : -num2;
    }
};