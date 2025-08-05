class Solution
{
public:
    bool hasCycle;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(numCourses, 0);
        vector<bool> inRec(numCourses, 0);
        hasCycle = false;
        for (auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];
            mp[b].push_back(a);
        }
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                dfs(mp, visited, inRec, st, i);
            }
        }
        if (hasCycle)
            return {};
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
    void dfs(unordered_map<int, vector<int>> &mp, vector<bool> &visited, vector<bool> &inRec, stack<int> &st, int &u)
    {
        visited[u] = true;
        inRec[u] = true;
        for (int &v : mp[u])
        {
            if (inRec[v])
            {
                hasCycle = true;
                return;
            }
            if (!visited[v])
            {
                dfs(mp, visited, inRec, st, v);
            }
        }
        inRec[u] = false;
        st.push(u);
    }
};