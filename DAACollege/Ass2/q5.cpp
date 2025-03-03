#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void primMST(vector<vector<pii>> &graph, int V)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto &[weight, v] : graph[u])
        {
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    int V = 5; // Number of vertices
    vector<vector<pii>> graph(V);

    graph[0].push_back({2, 1});
    graph[0].push_back({3, 2});
    graph[1].push_back({2, 0});
    graph[1].push_back({3, 3});
    graph[2].push_back({3, 0});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({3, 1});
    graph[3].push_back({1, 2});
    graph[3].push_back({5, 4});
    graph[4].push_back({4, 2});
    graph[4].push_back({5, 3});

    primMST(graph, V);
    return 0;
}
