class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        vector<int> Y(n + 1, 0);
        vector<int> N(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (customers[i] == 'Y')
            {
                Y[i] = 1 + (i > 0 ? Y[i - 1] : 0);
                N[i] = (i > 0 ? N[i - 1] : 0);
            }
            else
            {
                N[i] = 1 + (i > 0 ? N[i - 1] : 0);
                Y[i] = (i > 0 ? Y[i - 1] : 0);
            }
        }
        Y[n] = Y[n - 1];
        N[n] = N[n - 1];

        int mini = INT_MAX;
        int ans = 0;

        for (int i = 0; i <= n; i++)
        {
            int before_close = (i > 0 ? N[i - 1] : 0);
            int after_close = Y[n] - (i > 0 ? Y[i - 1] : 0);
            int sum = before_close + after_close;

            if (mini > sum)
            {
                mini = sum;
                ans = i;
            }
        }

        return ans;
    }
};