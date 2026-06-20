class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        int n = lights.size();

        vector<int> DAT(n + 1, 0);
        for (int i = 0; i < n; i++)
        {

            int v = lights[i];
            if (v == 0)
                continue;
            int l = max(0, i - v);
            int u = min(i + v, n - 1);

            DAT[l] += 1;
            DAT[u + 1] += -1;
        }

        int cumSum = 0;

        for (int i = 0; i < n; i++)
        {
            cumSum += DAT[i];
            DAT[i] = cumSum;
        }

        int ans = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (DAT[i] == 0)
            {
                count++;
            }
            else
            {
                ans += (count / 3);
                if (count % 3 != 0)
                {
                    ans++;
                }
                count = 0;
            }
        }

        if (count != 0)
        {
            ans += (count / 3);
            if (count % 3 != 0)
            {
                ans++;
            }
        }

        return ans;
    }
};
©leetcode