#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <stack> // Added queue header
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }

    void dfs(stack<int> &s, unordered_map<int, bool> &visited, vector<int> &ans)
    {

        int top = s.top();

        ans.push_back(top);
        visited[top] = true;

        for (auto x : adj[top])
        {
            if (!visited[x])
            {
                s.push(x);
                dfs(s, visited, ans);
            }
        }
        s.pop();
        return;
    }
    void dfsHelper()
    {
        stack<int> s;
        unordered_map<int, bool> visited;
        // visited[adj.begin()->first] = true;
        vector<int> ans;
        s.push(adj.begin()->first);
        dfs(s, visited, ans);

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        if (s.empty())
            cout << "now stack is empty finally" << endl;
    }
};

int main()
{
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    graph<int> g;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
    cout << "DFS Traversal: ";

    // Run DFS on the graph

    g.dfsHelper();

    return 0;
}
