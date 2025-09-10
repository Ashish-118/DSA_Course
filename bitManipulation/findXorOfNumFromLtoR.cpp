class Solution
{
public:
    int xor1toN(int n)
    {
        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }
    int findXOR(int l, int r)
    {
        return xor1toN(l - 1) ^ xor1toN(r);
    }
};
// t.c O(1) s.c O(1)