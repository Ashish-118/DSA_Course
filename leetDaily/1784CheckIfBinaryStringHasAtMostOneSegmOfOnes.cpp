class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int ones = 0;

        for (auto x : s)
            if (x == '1')
                ones++;

        int temp = ones;

        for (auto x : s)
        {
            if (x == '0')
            {

                if (temp != ones)
                {
                    return false;
                }
            }
            else
            {
                temp--;
                if (!temp)
                    break;
            }
        }

        return true;
    }
};