class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return (1 == __builtin_popcountll((long long)n));
    }
};