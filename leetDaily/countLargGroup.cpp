class Solution
{
    int sumOfDigits(int n)
    {
        if (n == 0)
            return 0;
        int d = n % 10;
        int r = n / 10;
        int sum = d + sumOfDigits(r);
        return sum;
    }

public:
    int countLargestGroup(int n)
    {

        map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            int v = sumOfDigits(i);
            m[v]++;
        }

        int maxi = INT_MIN;
        int count = 0;
        for (auto x : m)
        {
            if (x.second > maxi)
            {
                maxi = x.second;
                count = 1;
            }
            else if (x.second == maxi)
            {
                count++;
            }
        }
        return count;
    }
};