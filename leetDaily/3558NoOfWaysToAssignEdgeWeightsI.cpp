class Solution {
public:
    unordered_map<int, list<int>> adj;
    vector<bool> visited;
    int mod = 1000000007;
    int depth(int node, int d) {
        visited[node]=true;
        int maxi = d;
        for (auto ngb : adj[node]) {
            if(visited[ngb]) continue;
            maxi = max(maxi, depth(ngb, d + 1));
        }

        return maxi;
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxi=-1;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            maxi=max({maxi,e[1],e[0]});
        }
        visited.assign(maxi+1,false);
        int d = depth(1, 0);
    


        return modPow(2,d-1);

    
    }
};