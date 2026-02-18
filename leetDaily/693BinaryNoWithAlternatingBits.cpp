class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int top = n & 1;
        int count = __builtin_popcount(n);

        if (top)
            count--;

        for (int i = 1; i < 32 && count; i++)
        {

            int curr = (n >> i) & 1;

            if (top == curr)
                return false;
            if (curr)
                count--;
            top = curr;
        }

        return true;
    }
};