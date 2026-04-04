class EventManager
{
public:
    unordered_map<int, int> data;
    unordered_map<int, set<int>> priorityData;
    set<int> st;
    EventManager(vector<vector<int>> &events)
    {
        for (auto x : events)
        {
            data[x[0]] = x[1];
            priorityData[x[1]].insert(x[0]);
            st.insert(x[1]);
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        int oldPriority = data[eventId];
        priorityData[oldPriority].erase(
            priorityData[oldPriority].find(eventId));
        if (priorityData[oldPriority].size() == 0)
        {
            priorityData.erase(oldPriority);
            st.erase(st.find(oldPriority));
        }

        data[eventId] = newPriority;
        st.insert(newPriority);
        priorityData[newPriority].insert(eventId);
    }

    int pollHighest()
    {
        if (st.size() == 0)
            return -1;
        auto high = *st.rbegin();
        int id = *priorityData[high].begin();
        priorityData[high].erase(priorityData[high].find(id));
        if (priorityData[high].size() == 0)
        {
            priorityData.erase(high);
            st.erase(st.find(high));
        }
        data.erase(id);

        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */