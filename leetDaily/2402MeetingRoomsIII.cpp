class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> used(n, 0);
        sort(begin(meetings), end(meetings));

        set<pair<long long, int>> st;
        for (int i = 0; i < n; i++)
        {
            st.insert({0, i});
        }

        int maxUsed = 0;
        int ans = INT_MAX;

        for (auto m : meetings)
        {
            int start = m[0], end = m[1];
            auto front = *st.begin();
            int room = front.second;
            long long free = front.first;

            if (free >= start)
            {
                st.erase(st.begin());
                st.insert({free + end - start, room});
            }
            else
            {
                for (auto it : st)
                {
                    if (it.first > start)
                        break;
                    if (it.second < room)
                    {
                        room = it.second;
                        free = it.first;
                    }
                }
                auto found = st.find({free, room});
                st.erase(found);
                st.insert({end, room});
            }

            used[room]++;
            if (maxUsed == used[room])
            {
                ans = min(ans, room);
            }
            else if (maxUsed < used[room])
            {
                maxUsed = used[room];
                ans = room;
            }
        }

        return ans;
    }
};

/// time complexity: O(m log n)