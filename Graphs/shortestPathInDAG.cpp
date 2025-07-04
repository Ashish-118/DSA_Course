#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    void topo(int node, stack<int> &st, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor.first])
            {
                topo(neighbor.first, st, visited);
            }
        }
        st.push(node);
    }

    void shortestPath(stack<int> &st, unordered_map<int, bool> &visited, vector<int> &dist, int src)
    {

        dist[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX)
            {
                for (auto x : adj[node])
                {
                    int neighbor = x.first;
                    int weight = x.second;
                    if (dist[node] + weight < dist[neighbor])
                    {
                        dist[neighbor] = dist[node] + weight;
                    }
                }
            }
        }
    }
};
int main()
{

    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.printAdjList();

    stack<int> st;
    unordered_map<int, bool> visited;
    for (auto i : g.adj)
    {
        if (!visited[i.first])
        {
            g.topo(i.first, st, visited);
        }
    }

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    vector<int> dist;
    for (int i = 0; i < g.adj.size(); i++)
        dist.push_back(INT_MAX);

    int src = 1;
    g.shortestPath(st, visited, dist, src);
    cout << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}