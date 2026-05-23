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

// approach using upper_bound

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                            vector<int> &worker)
    {
        int n1 = profit.size(), n2 = worker.size();

        vector<int> prefixProfit(n1, 0);
        vector<pair<int, int>> v;
        for (int i = 0; i < n1; i++)
        {
            v.push_back({difficulty[i], profit[i]});
        }
        sort(begin(v), end(v));
        prefixProfit[0] = v[0].second;

        for (int i = 1; i < n1; i++)
        {
            prefixProfit[i] = max(prefixProfit[i - 1], v[i].second);
        }

        int ans = 0;

        auto cmp = [&](int val, const pair<int, int> p)
        {
            return val < p.first;
        };

        for (auto w : worker)
        {
            int IndexUpperBound =
                upper_bound(begin(v), end(v), w, cmp) - begin(v);

            if (IndexUpperBound)
            {
                ans += prefixProfit[IndexUpperBound - 1];
            }
        }

        return ans;
    }
};

// approach -3 without using upper_bound

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                            vector<int> &worker)
    {
        int n1 = profit.size(), n2 = worker.size();

        vector<pair<int, int>> v;
        for (int i = 0; i < n1; i++)
        {
            v.push_back({difficulty[i], profit[i]});
        }
        sort(begin(v), end(v));
        sort(begin(worker), end(worker));

        int j = 0;
        int ans = 0;
        int prev = 0;

        for (auto w : worker)
        {
            while (j < n1 && v[j].first <= w)
            {
                prev = max(prev, v[j].second);
                j++;
            }

            ans += prev;
        }

        return ans;
    }
};