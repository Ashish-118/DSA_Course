//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Position this line where user code will be pasted.
class Solution
{
public:
    void dfs(int node, unordered_map<int, bool> &visited,
             vector<vector<int>> &adj, vector<int> &index, int &count, int i,
             vector<int> &code, int c)

    {

        count++;
        visited[node] = true;
        index[node] = i;
        code[node] = c;
        for (auto x : adj[node])
        {
            if (!visited[x])
            {

                dfs(x, visited, adj, index, count, i + 1, code, c);
            }
            else if (visited[x] && code[node] != code[x])
            {
                count--;
                dfs(x, visited, adj, index, count, i + 1, code, c);
            }
            else if (index[node] > index[x])
            {
                count = count - (index[node] - index[x]);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj)
    {
        int count = 0;
        int in = 1;
        int v = adj.size();
        vector<int> index(v, 0);
        cout << "size " << v << endl;
        unordered_map<int, bool> visited;
        int c = 0;
        vector<int> code(v, 0);

        for (int i = 0; i < v; i++)
        {

            if (!visited[i])
            {
                cout << "before for Node " << i << " c " << c << " " << count << endl;
                dfs(i, visited, adj, index, count, in, code, c);

                cout << "for Node " << i << " c " << c << " " << count << endl;
                c++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends