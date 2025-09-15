class Solution
{
public:
    int minOperations(string s)
    {

        if (count(s.begin(), s.end(), 'a') == s.length())
            return 0;

        int n1 = 1000, n2 = -1;
        for (auto &x : s)
        {
            int v = x - 'a';
            if (x != 'a')
            {
                n1 = min(n1, v);
                n2 = max(n2, v);
            }
        }

        char c = 'a' + n2;

        return (n2 - n1 + ('z' - c) + 1);
    }
};