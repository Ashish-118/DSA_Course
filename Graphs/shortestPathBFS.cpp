#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <list>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }
    }

    stack<int> st;
    st.push(t);
    vector<int> ans;
    ans.push_back(t);
    while (st.top() != s)
    {
        int top = st.top();
        int p = parent[top];
        st.push(p);
        ans.push_back(p);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
