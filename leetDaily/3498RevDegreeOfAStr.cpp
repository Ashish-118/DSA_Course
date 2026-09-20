class Solution
{
public:
    int reverseDegree(string s)
    {
        int sum = 0;
        int i = 1;

        for (auto x : s)
        {
            int idx = x - 'a';
            sum += (26 - idx) * (i);
            i++;
        }

        return sum;
    }
};