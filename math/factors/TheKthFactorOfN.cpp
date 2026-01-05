class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> list;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                list.push_back(i);

                int div2 = n / i;
                if (div2 != i)
                {
                    list.push_back(div2);
                }
            }
        }
        sort(begin(list), end(list));
        if (k <= list.size())
            return list[k - 1];
        else
            return -1;
    }
};