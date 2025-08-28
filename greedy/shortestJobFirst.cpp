// User function Template for C++

// Back-end complete function Template for C++

class Solution
{
public:
    long long solve(vector<int> &bt)
    {

        sort(begin(bt), end(bt));
        int startTime = 0;
        int waitingTime = 0;
        int n = bt.size();

        for (auto &burstTime : bt)
        {
            waitingTime += startTime;
            startTime += burstTime;
        }

        return waitingTime / n;
    }
};