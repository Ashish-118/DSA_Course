class Solution
{
public:
    string largestOddNumber(string num)
    {

        int end = -1;
        int n = num.length();

        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') & 1)
            {
                end = i;
                break;
            }
        }

        if (end == -1)
            return "";

        return num.substr(0, end + 1);
    }
};