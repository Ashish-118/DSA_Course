class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        int n = workerTimes.size();

        vector<long long> workerCount(n, 1);

        for (int i = 0; i < n; i++)
        {
            pq.push({workerTimes[i], i});
        }

        long long ans = -1;

        while (mountainHeight)
        {

            auto top = pq.top();
            int worker = top.second;
            ans = max(ans, top.first);

            pq.pop();
            workerCount[worker]++;
            pq.push({top.first + workerCount[worker] * workerTimes[worker],
                     worker});

            mountainHeight--;
        }

        return ans;
    }
};