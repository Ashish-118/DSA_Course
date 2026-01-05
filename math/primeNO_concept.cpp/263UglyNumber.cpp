class Solution
{
public:
    bool isUgly(int n)
    {

        vector<int> primeFactors;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                primeFactors.push_back(i);
                while (n % i == 0)
                {
                    n = n / i;
                }
            }
        }

        if (n != 1)
            primeFactors.push_back(n);

        for (auto x : primeFactors)
        {
            if (x != 2 && x != 3 && x != 5)
                return false;
        }

        return true;
    }
};

// most optimal
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;

        while (n % 2 == 0)
            n = n / 2;
        while (n % 3 == 0)
            n = n / 3;
        while (n % 5 == 0)
            n = n / 5;

        return n == 1;
    }
};