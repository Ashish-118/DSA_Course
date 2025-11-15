class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source,
                              int target)
    {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < routes.size(); i++)
        {
            for (auto x : routes[i])
            {
                mp[x].push_back(i);
            }
        }

        vector<bool> visited(routes.size(), false);

        int count = 0;
        queue<int> q;
        for (auto bus : mp[source])
        {
            q.push(bus);
            visited[bus] = true;
        }

        while (!q.empty())
        {
            int size = q.size();
            count++; // taking one more bus

            while (size--)
            {
                int currBus = q.front();
                q.pop();

                for (auto stop : routes[currBus])
                {
                    if (stop == target)
                        return count;

                    for (auto nextBus : mp[stop])
                    {
                        if (!visited[nextBus])
                        {
                            visited[nextBus] = true;
                            q.push(nextBus);
                        }
                    }
                }
            }
        }

        return -1;
    }
};