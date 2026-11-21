class Solution {
public:
    unordered_map<int, list<int>> adj;

    void solve(int node, vector<int>& p, vector<int>& a, string& s) {

        int tmp = a[s[node]-'a'];

        if (node != 0 && tmp != -1) {
            p[node] = tmp;
        }

        a[s[node]-'a'] = node;

        for (auto& ngb : adj[node]) {
            solve(ngb, p, a, s);
        }

        a[s[node]-'a'] = tmp;
    }

    int fn(int node, vector<int>& ans) {
        int len = 1;

        for (auto& ngb : adj[node]) {
            len += fn(ngb, ans);
        }

        return ans[node] = len;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> a(26, -1);

        solve(0, parent, a, s);

        adj.clear();

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n,0);

        fn(0,ans);

        return ans;
    }
};