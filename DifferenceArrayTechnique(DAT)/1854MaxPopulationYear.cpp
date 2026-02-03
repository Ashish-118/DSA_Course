class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> dat(2051, 0);

        for (auto log : logs)
        {
            dat[log[0]] += 1;
            dat[log[1]] -= 1;
        }

        int cumSum = 0;
        int maxPop = 0;
        int year = 0;

        for (int i = 0; i < 2051; i++)
        {
            cumSum += dat[i];

            if (maxPop < cumSum)
                year = i;
            maxPop = max(maxPop, cumSum);
        }

        return year;
    }
};