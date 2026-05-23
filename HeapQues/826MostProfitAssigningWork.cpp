class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                            vector<int> &worker)
    {
        priority_queue<pair<int, int>> maxHeap;

        sort(begin(worker), end(worker), greater<int>());

        int n = difficulty.size();
        for (int i = 0; i < n; i++)
        {
            maxHeap.push({profit[i], difficulty[i]});
        }

        int ans = 0;

        for (auto w : worker)
        {

            while (!maxHeap.empty() && maxHeap.top().second > w)
            {

                maxHeap.pop();
            }

            if (!maxHeap.empty())
            {
                ans += maxHeap.top().first;
            }
        }

        return ans;
    }
};