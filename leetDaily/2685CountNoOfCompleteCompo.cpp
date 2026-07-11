class Solution {
public:
    vector<bool> visited;
    unordered_map<int, list<int>> adj;

    void dfs(int node, int& count, vector<int>& temp) {
        visited[node] = true;
        temp.push_back(node);
        count++;

        for (auto& ngb : adj[node]) {
            if (!visited[ngb]) {

                dfs(ngb, count, temp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        visited.assign(n, false);

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int c = 0;
            vector<int> temp;
            dfs(i, c, temp);
            c--;

            cout << c << endl;
            bool check = true;
            for (auto t : temp) {
                if (adj[t].size() != c) {
                    check = false;
                }
            }

            if (check) {
                count++;
            }
        }

        return count;
    }
};