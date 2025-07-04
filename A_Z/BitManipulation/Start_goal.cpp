class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int result = (start ^ goal);
        return __builtin_popcount(result);
    }
};