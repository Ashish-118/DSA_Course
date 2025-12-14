class Solution
{
public:
    int countOdds(int low, int high)
    {
        int len = high - low + 1;

        if (len % 2 == 0)
            return len / 2;

        if (low & 1)
            return len / 2 + 1;
        return len / 2;
    }
};