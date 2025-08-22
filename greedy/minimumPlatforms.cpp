class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        vector<pair<int, int>> dur;
        for (int i = 0; i < arr.size(); i++)
        {
            dur.push_back({arr[i], dep[i]});
        }

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first < b.first;
        };
        sort(dur.begin(), dur.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(-1);

        for (auto &x : dur)
        {
            int top = pq.top();
            if (top < x.first)
            {
                pq.pop();
                pq.push(x.second);
            }
            else
            {
                pq.push(x.second);
            }
        }

        return pq.size();
    }
};
