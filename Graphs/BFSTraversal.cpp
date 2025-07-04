#include <iostream>
#include <list>
#include <unordered_map>
#include <queue> // Added queue header
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

    void bfs()
    {
        unordered_map<T, bool> visited;
        queue<T> q;

        // Start BFS from the first node in the adjacency list
        T startNode = adj.begin()->first;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty())
        {
            T front = q.front(); // Changed int to T
            cout << front << " ";
            q.pop();

            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
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
    cout << "BFS Traversal: ";
    g.bfs();

    return 0;
}
