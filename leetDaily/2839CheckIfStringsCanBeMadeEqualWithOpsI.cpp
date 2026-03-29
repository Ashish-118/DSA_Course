class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {

        if (s1[0] != s2[0])
        {
            if (s1[0] == s2[2])
            {
                swap(s2[0], s2[2]);
            }
            else
                return false;
        }

        if (s1[1] != s2[1])
        {
            if (s1[1] == s2[3])
            {
                swap(s2[1], s2[3]);
            }
            else
                return false;
        }

        if (s1[2] != s2[2])
            return false;
        if (s1[3] != s2[3])
            return false;

        return true;
    }
};