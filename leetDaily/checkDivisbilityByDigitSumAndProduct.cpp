class Solution
{
public:
    int sum(int n)
    {
        if (n == 0)
            return 0;
        int last = n % 10;
        return last + sum(n / 10);
    }

    int mul(int n)
    {
        if (n == 0)
            return 1;
        int last = n % 10;
        return last * mul(n / 10);
    }
    bool checkDivisibility(int n)
    {
        int check = sum(n) + mul(n);

        if (n % check == 0)
            return true;
        else
            return false;
    }
};