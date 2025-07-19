class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        vector<int> gaps;
        int top = 0;

        for (int i = 0; i < startTime.size(); i++)
        {
            gaps.push_back(abs(top - startTime[i]));
            top = endTime[i];
        }

        if (top < eventTime)
        {
            gaps.push_back(abs(top - eventTime));
        }

        vector<int> eventDuration;
        for (int i = 0; i < startTime.size(); i++)
        {
            eventDuration.push_back(abs(startTime[i] - endTime[i]));
        }

        int maxi = INT_MIN;

        for (int i = 0; i < eventDuration.size(); i++)
        {
            bool pos = false;

            for (int j = 0; j < gaps.size(); j++)
            {
                if (j != i && j != (i + 1) && gaps[j] >= eventDuration[i])
                {
                    pos = true;
                    break;
                }
            }

            if (pos)
            {
                maxi = max(maxi, gaps[i] + ((i + 1) >= gaps.size() ? 0 : gaps[i + 1]) + eventDuration[i]);
            }
            else
            {
                maxi = max(maxi, gaps[i] + ((i + 1) >= gaps.size() ? 0 : gaps[i + 1]));
            }
        }

        return maxi;
    }
}; // o(n^2)

// O(nlogn) solution

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        vector<int> gaps;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            gaps.push_back(startTime[i] - p);
            p = endTime[i];
        }
        gaps.push_back(eventTime - p); // pushing the last gap
        int ans = 0;
        // Case 1 : block is getting shifted
        for (int i = 0; i < gaps.size() - 1; i++)
        {
            ans = max(ans, gaps[i] + gaps[i + 1]);
        }
        // Case 2 : block is getting jumped
        vector<int> sgaps = gaps;
        sort(sgaps.rbegin(), sgaps.rend());
        int top1 = sgaps[0], top2 = sgaps[1], top3 = sgaps[2];
        for (int i = 0; i < n; i++)
        {
            int leftgap = gaps[i];
            int rightgap = gaps[i + 1];
            int mx = max(leftgap, rightgap);
            int mn = min(leftgap, rightgap);
            int event = endTime[i] - startTime[i];
            int select1 = 0, select2 = 0;
            if (mx != top1)
                select1 = 1;
            else
            {
                if (mn != top2)
                    select2 = 1;
            }

            if (select1)
            {
                if (top1 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
            else if (select2)
            {
                if (top2 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
            else
            {
                if (top3 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
        }
        return ans;
    }
};

// O(n) solution
class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        vector<int> gaps;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            gaps.push_back(startTime[i] - p);
            p = endTime[i];
        }
        gaps.push_back(eventTime - p); // pushing the last gap
        int ans = 0;
        // Case 1 : block is getting shifted
        for (int i = 0; i < gaps.size() - 1; i++)
        {
            ans = max(ans, gaps[i] + gaps[i + 1]);
        }
        // Case 2 : block is getting jumped
        vector<int> sgaps = gaps;

        int top1 = 0, top2 = 0, top3 = 0;
        for (auto x : gaps)
        {
            if (x >= top1)
            {
                top3 = top2;
                top2 = top1;

                top1 = x;
            }
            else if (x >= top2)
            {
                top3 = top2;
                top2 = x;
            }
            else if (x >= top3)
            {
                top3 = x;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int leftgap = gaps[i];
            int rightgap = gaps[i + 1];
            int mx = max(leftgap, rightgap);
            int mn = min(leftgap, rightgap);
            int event = endTime[i] - startTime[i];
            int select1 = 0, select2 = 0;
            if (mx != top1)
                select1 = 1;
            else
            {
                if (mn != top2)
                    select2 = 1;
            }

            if (select1)
            {
                if (top1 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
            else if (select2)
            {
                if (top2 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
            else
            {
                if (top3 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
        }
        return ans;
    }
};
