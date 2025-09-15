class Solution
{
public:
    void print_divisors(int n)
    {
        vector<int> small, large;
        int limit = sqrt(n);

        for (int i = 1; i <= limit; i++)
        {
            if (n % i == 0)
            {
                small.push_back(i);
                if (i != n / i)
                { // avoid double-counting perfect square
                    large.push_back(n / i);
                }
            }
        }

        // Print smaller divisors first
        for (int x : small)
            cout << x << " ";
        // Then larger divisors in reverse order
        for (int i = large.size() - 1; i >= 0; i--)
            cout << large[i] << " ";
    }
};
