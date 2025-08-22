class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {

        vector<pair<int, int>> jobs;
        int maxDead = 0;
        for (int i = 0; i < deadline.size(); i++)
        {
            jobs.push_back({deadline[i], profit[i]});
            maxDead = max(maxDead, deadline[i]);
        }
        auto cmp = [&](pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        };

        sort(begin(jobs), end(jobs), cmp);

        vector<bool> day(maxDead + 1, false);
        int countprofit = 0;
        int count = 0;
        for (auto &job : jobs)
        {
            for (int d = job.first; d > 0; d--)
            { // start from job.deadline and go down to 1
                if (!day[d])
                {
                    day[d] = true;
                    count++;
                    countprofit += job.second;
                    break;
                }
            }
        }

        return {count, countprofit};
    }
};

// using dsu

class Solution
{
public:
    vector<int> parent;

    // Find with path compression
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union: mark x as filled, so connect it to x-1
    void merge(int x, int y)
    {
        parent[x] = y;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        int maxDead = 0;

        for (int i = 0; i < n; i++)
        {
            jobs.push_back({profit[i], deadline[i]});
            maxDead = max(maxDead, deadline[i]);
        }

        // Sort jobs by profit descending
        sort(jobs.rbegin(), jobs.rend());

        // Initialize DSU: each slot points to itself
        parent.resize(maxDead + 1);
        for (int i = 0; i <= maxDead; i++)
            parent[i] = i;

        int count = 0, totalProfit = 0;

        for (auto &job : jobs)
        {
            int prof = job.first;
            int dead = job.second;

            int avail = find(dead);
            if (avail > 0)
            {
                // assign job to avail slot
                count++;
                totalProfit += prof;
                merge(avail, avail - 1); // mark as filled
            }
        }

        return {count, totalProfit};
    }
};
