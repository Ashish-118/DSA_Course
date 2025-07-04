#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <set>
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

    void shortestPath(vector<int> &dist, set<pair<int, int>> &entry)++ ++ +
    {

        while (!entry.empty())
        {
            auto top = *(entry.begin());
            int nodeDistance = top.first;
            int node = top.second;
            entry.erase(entry.begin());

            for (auto x : adj[node])
            {
                if (nodeDistance + x.second < dist[x.first])
                {
                    auto record = entry.find({dist[x.first], x.first});
                    dist[x.first] = nodeDistance + x.second;
                    if (record != entry.end())
                    {
                        entry.erase(record);
                    }
                    entry.insert({dist[x.first], x.first});
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

    unordered_map<int, bool> visited;

    vector<int> dist;
    for (int i = 0; i < g.adj.size(); i++)
        dist.push_back(INT_MAX);

    set<pair<int, int>> entry; //{node distnace,node}
    entry.insert({0, 0});
    g.shortestPath(dist, entry);
    cout << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}