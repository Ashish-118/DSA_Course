#include <iostream>
#include <list>
#include <unordered_map>
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

    return 0;
}