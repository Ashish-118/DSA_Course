class TaskManager
{
public:
    unordered_map<int, int> TasksPriority;
    unordered_map<int, int> userID;
    set<pair<int, int>> st;
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &x : tasks)
        {
            add(x[0], x[1], x[2]);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        TasksPriority[taskId] = priority;
        userID[taskId] = userId;
        st.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority)
    {
        int oldPriority = TasksPriority[taskId];
        auto it = st.find({-oldPriority, -taskId});
        st.erase(it);
        TasksPriority[taskId] = newPriority;
        st.insert({-newPriority, -taskId});
    }

    void rmv(int taskId)
    {
        int priority = TasksPriority[taskId];
        auto it = st.find({-priority, -taskId});
        st.erase(it);

        TasksPriority.erase(taskId);
        userID.erase(taskId);
    }

    int execTop()
    {
        if (st.empty())
            return -1;

        auto [p, t] = *st.begin();
        int taskId = -t;
        int user = userID[taskId];
        rmv(taskId);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */