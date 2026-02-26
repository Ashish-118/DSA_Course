class Solution
{
public:
    int numSteps(string s)
    {
        string str = '0' + s;
        int len = str.length();

        auto check = [&](string t)
        {
            int one = 0;
            for (auto x : t)
                if (x == '1')
                    one++;

            return one == 1 && t[t.length() - 1] == '1';
        };

        int count = 0;

        while (!check(str))
        {

            count++;

            if (str[len - 1] == '1')
            {
                int carry = 1;

                for (int i = len - 1; i >= 0; i--)
                {
                    if (str[i] == '1')
                    {
                        str[i] = '0';
                    }
                    else
                    {
                        str[i] = '1';
                        carry = 0;
                    }

                    if (carry == 0)
                        break;
                }
            }
            else
            {
                for (int i = len - 1; i > 0; i--)
                {
                    str[i] = str[i - 1];
                }
                str[0] = '0';
            }
        }

        return count;
    }
};