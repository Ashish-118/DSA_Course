class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        char topColor = '-';
        int maxTime = 0, totalSum = 0, count = 0, ans = 0;

        for (int i = 0; i < neededTime.size(); i++)
        {
            if (topColor != colors[i])
            {
                count = 1;
                ans += (totalSum - maxTime);
                maxTime = neededTime[i];
                topColor = colors[i];
                totalSum = neededTime[i];
            }
            else
            {
                count++;
                maxTime = max(maxTime, neededTime[i]);
                totalSum += neededTime[i];
            }
        }
        ans += (totalSum - maxTime);

        return ans;
    }
};