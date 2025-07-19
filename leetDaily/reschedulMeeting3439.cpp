class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        vector<int> gaps;
        int top = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            gaps.push_back(abs(top - startTime[i]));
            top = endTime[i];
        }
        if (abs(top - eventTime))
            gaps.push_back(abs(top - eventTime));

        int sum = 0;

        for (int i = 0; i <= k && i < gaps.size(); i++)
        {
            sum += gaps[i];
        }
        int ans = sum;
        for (int i = 1; i + k < gaps.size(); i++)
        {
            sum -= gaps[i - 1];
            sum += gaps[k + i];
            ans = max(ans, sum);
        }
        return ans;
    }
};