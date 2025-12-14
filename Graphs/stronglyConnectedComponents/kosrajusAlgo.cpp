#include <bits/stc++.h>
using namespace std;

void topo(int node, unordered_map<int, vector<int>> &adj, stack<int> &st, vector<bool> &visited)
{
    visited[node] = true;

    for (auto x : adj[node])
    {
        if (!visited[x])
        {
            topo(x, adj, st, visited);
        }
    }

    st.push(node);
}

void dfs(int node, unordered_map<int, vector<int>> &transponsed, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (auto x : transponsed[node])
    {
        if (!visited[x])
        {
            dfs(x, transponsed, visited);
        }
    }
}
int main()
{

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, vector<int>> revAdj;
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter edges (u v) format: " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    stack<int> st;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topo(i, adj, st, visited);
        }
    }
    visited.assign(n, false);
    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            count++;
            cout << "STRONGLY CONNECTED COMPONENT: " << count << endl;
            dfs(node, revAdj, visited);
            cout << endl;
        }
    }

    return 0;
}